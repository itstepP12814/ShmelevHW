using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Linq.Expressions;

namespace NoteBookLib
{
    public class NoteBook
    {
        List<Record> records;
        List<Record> foundBy;
        int nextResultPtr;

        public NoteBook()
        {
            records = new List<Record>();
        }

        public Record this[string index]
        {
            get { return findNextByFirstName(index); }
            set
            {
                Record temp = findNextByFirstName(index);
                temp = value;
            }
        }
        public int Count { get { return records.Count; } }
        public Record this[int index]
        {
            get { return records[index]; }
            set { records[index] = value; }
        }
        public void Add(string firstName, string lastName, string bithday, string email, string phoneNumber)
        {
            Record record = new Record(firstName, lastName, bithday, email, phoneNumber);
            records.Add(record);
            records.Sort(new AlphabetAscendSorter());
        }

        public void Remove(int index)
        {
            records.RemoveAt(index);
        }

        public class AlphabetAscendSorter : IComparer<Record>
        {
            public int Compare(Record x, Record y)
            {//Сортировка идет только по фамилии
                return string.Compare(x.LastName, y.LastName);
            }
        }

        public Record findNextByFirstName(string firstName)
        {
            string paramName = GetName(() => firstName);//LINQ выражение - выдает имя переменной
            return findNext(firstName, paramName);
        }

        public Record findNextByLastName(string lastName)
        {
            string paramName = GetName(() => lastName);//LINQ выражение - выдает имя переменной
            return findNext(lastName, paramName);
        }

        public Record findNextByBithDay(string bithDay)
        {
            string paramName = GetName(() => bithDay);//LINQ выражение - выдает имя переменной
            return findNext(bithDay, paramName);
        }

        public Record findNextByEmail(string email)
        {
            string paramName = GetName(() => email);//LINQ выражение - выдает имя переменной
            return findNext(email, paramName);
        }

        public Record findNextByPhoneNumber(string phoneNumber)
        {
            string paramName = GetName(() => phoneNumber);//LINQ выражение - выдает имя переменной
            return findNext(phoneNumber, paramName);
        }
        Record findNext(object searchParam, string paramName)
        { //Метод обрабатывает выдачу следующего найденного элемента из массива результатов поиска
            //Ищем номер необходимого параметра по его имени
            foreach (KeyValuePair<int, string> kvp in Record.FieldsNames)
            {
                if (paramName == kvp.Value) //Если имя параметра для поиска найдено
                {
                    if (foundBy != null && searchParam == foundBy[0].fields[kvp.Key])
                    {
                        if (nextResultPtr < foundBy.Count - 1)
                            nextResultPtr++;
                        return foundBy[nextResultPtr];
                    }
                    else
                    {
                        nextResultPtr = 0;
                        foundBy = SearchBy(searchParam, kvp.Key);
                        return foundBy[nextResultPtr];
                    }
                }
            }
            throw new ArgumentException("Ошибка опеределения метода поиска.");
        }

        private List<Record> SearchBy(object searchParam, int paramNumber) //Обобщенный метод поиска
        {
            foundBy = new List<Record>();
            foreach (Record record in records)
            {
                if (record.fields[paramNumber] == searchParam)
                //ПОЧЕМУ при вводе данных из консоли обьекты сравниваются неуспешно, а при вызове функции внутри программы - успешно?
                {
                    foundBy.Add(record);
                }
            }
            if (foundBy.Capacity == 0)
            {
                throw new ApplicationException("Ничего не найдено.");
            }
            return foundBy;
        }

        static string GetName<T>(Expression<Func<T>> expr)
        {
            var member = ((MemberExpression)expr.Body).Member;
            return member.Name;
        }
    }

    public struct Record
    {
        public ArrayList fields; //Здесь хранятся значения
        static Dictionary<int, string> fieldsNames;
        public string FirstName { get { return (string)fields[0]; } }
        public string LastName { get { return (string)fields[1]; } }
        public string Bithday { get { return (string)fields[2]; } }
        public string Email { get { return (string)fields[3]; } }
        public string PhoneNumber { get { return (string)fields[4]; } }
        public static Dictionary<int, string> FieldsNames { get { return fieldsNames; } }
        static Record()
        {
            fieldsNames = new Dictionary<int, string>()
            {
                {0, "firstName"},
                {1, "lastName"},
                {2, "bithDay"},
                {3, "email"},
                {4, "phoneNumber"}
                //Этот словарь будет использоваться для определения, по какому параметру будет проводиться поиск
                //что позволит подставлять в функцию поиска этот самый параметр
            };
        }
        internal Record(string firstName, string lastName, string bithDay, string email, string phoneNumber)
        {
            fields = new ArrayList() { firstName, lastName, bithDay, email, phoneNumber };
        }
    }
}
