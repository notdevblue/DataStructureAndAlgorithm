using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace EnglishDictionary
{
    class Program
    {
        static void Main(string[] args)
        {
            EngDictionary dictionary = new();
            char input;
            char[] inputKeys = { '1', '2', '3', '4', '5' };
            string[] menus = { "Insert", "Delete", "Search", "Print", "Quit" };

            Console.Clear();
            ConsoleTools.PrintTitle("Dictionary", inputKeys, menus);

            while(true) {
                Console.Clear();
                
                ConsoleTools.PrintTitle("Dictionary", inputKeys, menus);
                input = Console.ReadKey().KeyChar;

                Console.Clear();

                switch(input)
                {
                    case '1':
                        ConsoleTools.Input("Insert: ", result => {
                            if(dictionary.Add(result) == 0) {
                                System.Console.WriteLine($"Successfully added \"{result}\" to dictionary");
                            }
                            ConsoleTools.PressToContinue();
                        });
                        break;

                    case '2':
                        ConsoleTools.Input("Remove: " , result => {
                            if(dictionary.Remove(result) == 0) {
                                System.Console.WriteLine($"Successfully removed \"{result}\" from dictionary");
                            }
                            ConsoleTools.PressToContinue();
                        });
                        break;

                    case '3':
                        ConsoleTools.Input("Find: ", result => {
                            ConsoleTools.Print(dictionary.Find(result));
                            ConsoleTools.PressToContinue();
                        });
                        break;

                    case '4':
                        dictionary.Print();
                        ConsoleTools.PressToContinue();
                        break;

                    case '5':
                        return;

                    default:
                        break;
                }

                Console.Clear();
            }
        }
    }

    static class ConsoleTools
    {
        static public void Print<T>(T[] array)
        {
            System.Console.WriteLine("--- Output ---");
            for (int i = 0; i < array.Length; ++i) {
                System.Console.WriteLine($"{i}:\t{array[i]}");
            }
        }

        static public bool Input(string inputMessage, Action<string>? callback = null)
        {
            string? input;

            System.Console.Write(inputMessage);
            input = Console.ReadLine();

            if(input != null) {
                callback?.Invoke(input);
                return true;
            } else {
                return false;
            }
        }

        static public void PressToContinue()
        {
            System.Console.WriteLine("Press any key to continue...");
            System.Console.ReadKey();
        }

        static public void PrintTitle(string title, char[] inputkeys, string[] menus, char titleModifier = '-', int titleModifierCount = 3)
        {
            if(inputkeys.Length != menus.Length) {
                throw new ArgumentException();
            }

            for (int i = -titleModifierCount; i < titleModifierCount; ++i) {
                if(i == 0) {
                    System.Console.Write($" {title} ");
                }
                System.Console.Write(titleModifier);
            }

            System.Console.WriteLine("\r\n");

            for (int i = 0; i < inputkeys.Length; ++i) {
                System.Console.WriteLine($"{inputkeys[i]}. {menus[i]}");
            }

            System.Console.WriteLine();
        }
    }

    public class EngDictionary
    {
        private SortedSet<string> _englighSet;
        Regex regex;


        public EngDictionary()
        {
            _englighSet = new();
            regex = new Regex(@"^[a-zA-Z]+$"); // stackoverflow
        }

        public int Add(string value)
        {
            Match m = regex.Match(value);
            if(!m.Success) {
                System.Console.WriteLine("Only alphabet is accepted.");
                return 1;
            }

            if(_englighSet.Contains(value)) {
                System.Console.WriteLine($"Value: {value} already added.");
                return 1;
            } else {
                _englighSet.Add(value);
                return 0;
            }
        }

        public int Remove(string value)
        {
            if(!_englighSet.Contains(value)) {
                System.Console.WriteLine($"Value: {value} is already removed");
                return 1;
            } else {
                _englighSet.Remove(value);
                return 0;
            }
        }

        public string[] Find(char key)
        {
            return _englighSet.GetViewBetween(key.ToString(), NextAlphabet(key).ToString()).ToArray();
        }
        public string[] Find(string key)
        {
            string nextKey = $"{key.Remove(key.Length - 1)}{NextAlphabet(key[key.Length - 1])}";

            return _englighSet.GetViewBetween(key, nextKey).ToArray();
        }

        public void Print()
        {
            foreach(string item in _englighSet) {
                System.Console.WriteLine(item);
            }
        }

        private char NextAlphabet(char alphabet)
        {
            if(alphabet.CompareTo('z') == 0) {
                alphabet = 'a';
            } else if (alphabet.CompareTo('Z') == 0) {
                alphabet = 'Z';
            } else {
                ++alphabet;
            }

            return alphabet;
        }
    }
}