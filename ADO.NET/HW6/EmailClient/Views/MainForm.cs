using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EmailClient.Model;

namespace EmailClient
{
    public partial class MainForm : Form
    {
        private ContextMenuStrip contextMenu;
        private EmailDataModelContainer db;
        private ToolStripMenuItem add;
        Category rootNode;
        public MainForm()
        {
            InitializeComponent();
            RecipientTreeView.NodeMouseClick += (sender, e) =>
            {
                if (e.Button == MouseButtons.Right)
                {
                    RecipientTreeView.SelectedNode = e.Node;
                    RecipientTreeView.SelectedNode.ContextMenuStrip = contextMenuStrip1;
                }
            };

            db = new EmailDataModelContainer();
            
            try
            {
                rootNode = db.CategorySet.Where(c => c.LeftKey == 1).Select(c => c).Single();
            }
            catch (InvalidOperationException ex)
            {
                db.CategorySet.Add(new Category() { LeftKey = 1, RightKey = 2, Level = 1, Name = "Получатели" });
                db.SaveChanges();
                rootNode = db.CategorySet.Select(c => c).Single();
            }

            InitializeVisualTree();
        }

        void InitializeVisualTree()
        {
            RecipientTreeView.Nodes.Clear();
            RecipientTreeView.Nodes.Add(new TreeNode(rootNode.Name));
            RecipientTreeView.Nodes[0].Tag = rootNode.Id;
            List<Category> allNodes = db.CategorySet.Select(c => c).ToList();
            RecipientTreeView.Nodes[0] = NextNode(rootNode, RecipientTreeView.Nodes[0], allNodes);
        }
        /// <summary>
        /// Рекурсивный метод построение визульного дерева элементов
        /// </summary>
        /// <param name="parentCategory">Корневой элемент</param>
        /// <param name="parentVisualNode">Визуальный корневой узел</param>
        /// <param name="catList">Список категорий, из которого производится выборка</param>
        /// <returns></returns>
        static TreeNode NextNode(Category parentCategory, TreeNode parentVisualNode, List<Category> catList)
        {
            //////Если есть дочерние элементы
            if (parentCategory.LeftKey != parentCategory.RightKey - 1)
            {
                //Обходим и добавляем все непосредственные дочерние элементы
                var childNodes = catList.Where(c => c.LeftKey > parentCategory.LeftKey &&
                c.RightKey < parentCategory.RightKey && c.Level == parentCategory.Level + 1).
                Select(c => c);

                foreach (var node in childNodes)
                {
                    TreeNode newNode = new TreeNode(node.Name);
                    newNode.Tag = node.Id;

                    newNode.ContextMenuStrip = new ContextMenuStrip();
                    parentVisualNode.Nodes.Add(newNode);

                    NextNode(node, parentVisualNode.Nodes[0], catList);
                }
            }
            return parentVisualNode;
        }

        /// <summary>
        /// Метод добавляет категорию в указанное место дерева категорий
        /// </summary>
        /// <param name="parentId">Идентификатор категории из базы данных в который нужно добавить новую категорию</param>
        /// <param name="categoryName">Имя категории</param>
        void AddCategory(int parentId, string categoryName)
        {
            //Получаем родительский узел
            var parentNode = db.CategorySet.Where(cat => cat.Id == parentId).Select(cat => cat).Single();
            
            //Элементы, стоящие за выбранной ветвью
            var followingChilds = db.CategorySet.Where(cat => cat.LeftKey > parentNode.RightKey);

            //Получаем родительскую ветку
            var parentBranch = db.CategorySet.Where(cat => cat.RightKey >= parentNode.RightKey
                                                           && cat.LeftKey < parentNode.RightKey);

            //Смещаем индексы элементов после родительского дерева
            foreach (var child in followingChilds)
            {
                child.LeftKey += 2;
                child.RightKey += 2;
            }

            //Добавляем новый узел
            Category newCategory = new Category() { LeftKey = parentNode.RightKey, RightKey = parentNode.RightKey+1, Name = categoryName, Level = parentNode.Level+1};
            db.CategorySet.Add(newCategory);

            //Обновляем родительскую ветку
            foreach (var category in parentBranch)
            {
                category.RightKey += 2;
            }
            //Сохраняем внесенные изменения
            db.SaveChanges();
        }

        /// <summary>
        /// Удаление узла
        /// </summary>
        /// <param name="nodeId">Идентификатор удаляемого узла</param>
        void RemoveCategory(int nodeId)
        {
            //Удаляем узлы
            var nodeToDelete = db.CategorySet.Where(cat => cat.Id == nodeId).Select(cat => cat).Single();
            var childsToDelete = db.CategorySet.Where(cat => cat.LeftKey >= nodeToDelete.LeftKey &&
                                                             cat.RightKey <= nodeToDelete.RightKey);
            foreach (var category in childsToDelete)
            {
                db.CategorySet.Remove(category);
            }
            
            //Получаем родительскую ветку
            var parentBranch = db.CategorySet.Where(cat => cat.RightKey > nodeToDelete.RightKey
                                                           && cat.LeftKey < nodeToDelete.LeftKey);
            //Обновляем индексы родительского дерева (высчитываются новые ключи на основании количества детей элемента)
            foreach (var category in parentBranch)
            {
                category.RightKey = category.RightKey - (nodeToDelete.RightKey - nodeToDelete.LeftKey + 1);
            }

            //Получаем последующие узлы
            var followingNodes = db.CategorySet.Where(cat => cat.LeftKey > nodeToDelete.RightKey);
            
            //Обновляем индексы последующих узлов
            foreach (var followingNode in followingNodes)
            {
                followingNode.LeftKey = followingNode.LeftKey - (followingNode.RightKey - followingNode.LeftKey + 1);
                followingNode.RightKey = followingNode.RightKey - (followingNode.RightKey - followingNode.LeftKey + 1);
            }

            db.SaveChanges();

        }

        private void addCategoryMenuItem_Click(object sender, EventArgs e)
        {
            AddCategory((int)RecipientTreeView.SelectedNode.Tag, "lol");
            InitializeVisualTree();
        }

        private void removeCategoryMenuItem_Click(object sender, EventArgs e)
        {
            RemoveCategory((int)RecipientTreeView.SelectedNode.Tag);
            InitializeVisualTree();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            for (int i = 20; i <= 25; i++)
            {
                RemoveCategory(i);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AddCategory(1, "lol");
            InitializeVisualTree();
        }
    }
}
