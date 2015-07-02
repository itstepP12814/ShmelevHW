using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NoteBookLib;
namespace NoteBookWrapper
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Записная книжка.\n");
            NoteBook notes = new NoteBook();
            notes.Add("Галина", "Шупенева", "12.10", "jfdkjf@fjn.ru", "375447756786");
            notes.Add("Константин", "Шалопаев", "02.03", "1231231@fjn.ru", "375445546788");
            notes.Add("Иван", "Карлович", "05.08", "jkmio@fjn.ru", "375449890876");
            notes.Add("Иван", "Разин", "04.07", "rweuryw@fjn.ru", "375442345532");
            notes.Add("Евгений", "Падоркин", "12.11", "nbjbj@fjn.ru", "375448765786");

            //display(notes.findNextByFirstName("Иван"));

            while (true)
            {
                try
                {
                    menuCall(notes);
                }
                catch (ApplicationException ex)
                {
                    Console.WriteLine(ex.Message);
                }
                catch (FormatException ex)
                {
                    Console.WriteLine("Вы сделали неверный выбор.");
                }
            }
        }

        static void menuCall(NoteBook notes)
        {
            displayMenu();
            string input = Console.ReadLine();
            int numAnswer = Int32.Parse(input);
            switch (numAnswer)
            {
                case 1:
                    {
                        displaySearhMenu();
                        Console.WriteLine("Введите номер пункта:\n");
                        int answer = Int32.Parse(Console.ReadLine());
                        switch (answer)
                        {
                            case 1:
                                {
                                    Console.WriteLine("Введите имя для поиска:\n");
                                    string inStr = Console.ReadLine();
                                    display(notes.findNextByFirstName(inStr));
                                }
                                break;
                            case 2:
                                {
                                    Console.WriteLine("Введите фамилию для поиска:\n");
                                    string inStr = Console.ReadLine();
                                    display(notes.findNextByLastName(inStr));
                                }
                                break;
                            case 3:
                                {
                                    Console.WriteLine("Введите день рождения для поиска:\n");
                                    string inStrD = Console.ReadLine();
                                    if (inStrD.Length == 1)
                                    {
                                        inStrD = "0" + inStrD;
                                    }
                                    Console.WriteLine("Введите месяц рождения для поиска:\n");
                                    string inStrM = Console.ReadLine();
                                    if (inStrM.Length == 1)
                                    {
                                        inStrD = "0" + inStrM;
                                    }
                                    display(notes.findNextByBithDay(inStrD+"."+inStrM));
                                }
                                break;
                            case 4:
                                {
                                    Console.WriteLine("Введите email для поиска:\n");
                                    string inStr = Console.ReadLine();
                                    notes.findNextByEmail(inStr);
                                }
                                break;
                            case 5:
                                {
                                    Console.WriteLine("Введите номер телефона для поиска:\n");
                                    string inStr = Console.ReadLine();
                                    Int64.Parse(inStr);
                                    notes.findNextByPhoneNumber(inStr);
                                }
                                break;
                            default:
                                throw new FormatException();
                                break;
                        }
                    }
                    break;
                case 2:
                    {
                        Console.WriteLine("Введите данные нового контакта (для пропуска поля просто нажмите ВВОД):");
                        Console.WriteLine("\tВведите имя:");
                        string firstName = Console.ReadLine();
                        Console.WriteLine("\tВведите фамилию:");
                        string lastName = Console.ReadLine();
                        Console.WriteLine("\tВведите день рождения:");
                        string bDayStr = Console.ReadLine();
                        int trash;
                        if (Int32.TryParse(bDayStr, out trash))
                        {
                            if (bDayStr.Length == 1)
                            { //Добавляем ноль для чисел до 10
                                bDayStr = "0" + bDayStr;
                            }
                        }
                        Console.WriteLine("\tВведите месяц рождения:");
                        string bMonthStr = Console.ReadLine();
                        if (Int32.TryParse(bMonthStr, out trash))
                        {
                            if (bMonthStr.Length == 1)
                            { //Добавляем ноль для чисел до 10
                                bMonthStr = "0" + bMonthStr;
                            }
                        }
                        Console.WriteLine("\tВведите email:");
                        string email = Console.ReadLine();
                        Console.WriteLine("\tВведите номер телефона:");
                        long phone = Int64.Parse(Console.ReadLine());
                        string phoneStr = Convert.ToString(phone);
                        notes.Add(firstName, lastName, bDayStr + "." + bMonthStr, email, phoneStr);
                        display(notes.findNextByFirstName(firstName));
                    }
                    break;
                case 3:
                    {
                        Console.WriteLine("Выберите номер удаляемого контакта:\n");
                        displayAll(notes);
                        Console.WriteLine("Введите номер:\n");
                        int answer = Int32.Parse(Console.ReadLine());
                        if (answer > 0 && answer < notes.Count)
                            notes.Remove(answer - 1);
                        else
                            throw new FormatException();
                    }
                    break;
                case 4:
                    displayAll(notes);
                    break;
                default:
                    throw new FormatException();
                    break;
            }
        }

        static void displayAll(NoteBook notes)
        {
            for (int i = 0; i < notes.Count; ++i)
            {
                Console.WriteLine("{0}: {1} {2}: +{3}, день рождения - {4}, email - {5}", i + 1, notes[i].FirstName, notes[i].LastName, notes[i].PhoneNumber, notes[i].Bithday, notes[i].Email);
            }
        }
        static void display(Record rec)
        {
            Console.WriteLine("{0} {1}: +{2}, день рождения - {3}, email - {4}", rec.FirstName, rec.LastName, rec.PhoneNumber, rec.Bithday, rec.Email);
        }

        static void displayMenu()
        {
            Console.Write(@"
Введите номер действия, которое необходимо выполнить:
1 - Поиск
2 - Добавление нового контакта
3 - Удаление контакта
4 - Показать все записи
");
        }
        static void displaySearhMenu()
        {
            Console.Write(@"

Введите номер действия, которое необходимо выполнить:
1 - Поиск по имени
2 - Поиск по фамилии
3 - Поиск по дате рождения
4 - Поиск по адресу электронной почты
5 - Поиск по номеру телефона
");
        }
    }
}
