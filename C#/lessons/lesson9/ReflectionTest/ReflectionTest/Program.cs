//Попытка получить доступ к методам и классам библиотек с помощью рефлексии
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.IO;
using System.Linq.Expressions;

namespace ReflectionTest
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Assembly assembly = Assembly.LoadFrom("ComplexLib.dll");
                Type[] t1 = assembly.GetTypes();
                foreach (Type type in t1)
                {
                    Console.WriteLine("\n" + type.Name + ": " + type.BaseType);
                    //Получаем все члены класса, в том числе закрытие (используются флаги)
                    foreach (MemberInfo t in type.GetMembers())
                    {
                        Console.WriteLine("\t"+t.Name + " " + t.MemberType);
                    }
                    Console.WriteLine("\n\nКонструкторы:");

                    foreach (MemberInfo t in type.GetConstructors((BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.DeclaredOnly | BindingFlags.Public)))
                    {
                        Console.WriteLine(t.DeclaringType+"\n\t"+t.Name + " " + t.MemberType);
                    }
                }
                Console.ReadLine();
            }
            catch (FileNotFoundException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
