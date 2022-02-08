using System;
using System.Text;
using System.IO;
using System.Collections.Generic;

namespace HanVim
{
    class Program
    {

        static bool g_isEditmode = false;
        static List<char> g_inputBuffer = new List<char>();
        static List<List<char>> g_lines = new List<List<char>>();
        static int g_currentLine = 0;
        static int g_currentCol = -1;
        static bool g_bKeepgoing = true;
        static string g_path = "";


        static void Main(string[] args)
        {
            
            bool createFile = false;
            

            if(args.Length > 1) {
                System.Console.WriteLine("usage dotnet run [path] or dotnet run");
                return;
            }

            if(args.Length == 1) {
                g_path = args[0];
            }

            if(createFile = File.Exists(g_path))
            {
                int idx = 0;

                foreach (string line in File.ReadLines(g_path)) {
                    g_lines.Add(new List<char>());
                    foreach(char ch in line) {
                        g_lines[idx].Add(ch);
                    }
                    g_lines[idx].Add('\n');
                    ++idx;
                }
            }
            else {
                g_lines.Add(new List<char>());
                g_lines[0].Add('\n');
            }

            Console.Clear();
            Print();

            while(g_bKeepgoing) {
                Console.SetCursorPosition(g_currentCol + 1, g_currentLine);
                KeyInput();
                Console.Clear();
                Print();
            }

        }


        static void KeyInput()
        {
            ConsoleKeyInfo key = Console.ReadKey();

            switch(key.Key)
            {
                case ConsoleKey.Escape:
                    g_inputBuffer.Clear();
                    g_isEditmode = false;
                    return;

                case ConsoleKey.Enter:
                    if(g_isEditmode) {
                        AddNewLine();
                    } else {
                        Execute();
                    }

                    return;

                case ConsoleKey.Backspace:
                    if(g_isEditmode)
                    {
                        if (g_currentCol < 0)
                        {
                            if(g_currentLine != 0) {
                                RemoveLine();
                            }
                            return;
                        }

                        g_lines[g_currentLine].RemoveAt(g_currentCol--);
                    }
                    return;

                case ConsoleKey.UpArrow:
                    g_currentLine -= g_currentLine - 1 < 0 ? 0 : 1;
                    g_currentCol = g_currentCol >= g_lines[g_currentLine].Count - 1 ? g_lines[g_currentLine].Count - 2 : g_currentCol; // \n
                    return;

                case ConsoleKey.DownArrow:
                    g_currentLine += g_currentLine + 1 >= g_lines.Count ? 0 : 1;
                    g_currentCol = g_currentCol >= g_lines[g_currentLine].Count - 1 ? g_lines[g_currentLine].Count - 2 : g_currentCol; // \n
                    return;

                case ConsoleKey.LeftArrow:
                    g_currentCol -= g_currentCol - 1 < -1 ? 0 : 1;
                    return;

                case ConsoleKey.RightArrow:
                    g_currentCol += g_currentCol + 1 >= g_lines[g_currentLine].Count - 1 ? 0 : 1; // \n
                    return;

                case ConsoleKey.Home:
                    g_currentCol = -1;
                    return;
                case ConsoleKey.End:
                    g_currentCol = g_lines[g_currentLine].Count - 2;
                    return;
            }

            if(g_isEditmode) {
                g_lines[g_currentLine].Insert(++g_currentCol, key.KeyChar);
                return;
            }

            

            switch(key.KeyChar)
            {
                case 'i':
                    g_isEditmode = true;
                    break;

                default:
                    g_inputBuffer.Add(key.KeyChar);
                    break;
            }


        }


        static bool g_bQuitflag = false;
        static bool g_bSaveflag = false;

        static void Execute()
        {
            if(g_isEditmode) return;

            g_inputBuffer.ForEach(e => {
                if(CheckCommand(e) == -1) {
                    return;
                }
            });


            if(g_bSaveflag) {
                StringBuilder sb = new StringBuilder();
                g_lines.ForEach(e => {
                    e.ForEach(ch => {
                        sb.Append(ch);
                    });
                });

                File.WriteAllText(g_path, sb.ToString());
            }

            if(g_bQuitflag) {
                g_bKeepgoing = false;
            }
            
        }

        static int CheckCommand(char input)
        {
            switch (input)
            {
                case ':':
                    break;

                case 'w':
                    g_bSaveflag = true;
                    break;

                case 'q':
                    g_bQuitflag = true;
                    break;

                default:
                    return -1;
            }
            return 0;
        }

        static void Print()
        {
            g_lines.ForEach(e => {
                e.ForEach(ch => {
                    System.Console.Write(ch);
                });
            });
        }

        static void AddNewLine()
        {
            // insert: index 앞에, like vim

            List<char> newLine = new List<char>();

            for (int i = 0; i <= g_currentCol; ++i) {
                newLine.Add(g_lines[g_currentLine][i]);
            }

            for (int i = g_currentCol; i >= 0; --i) {
                g_lines[g_currentLine].RemoveAt(i);
            }

            if(g_lines[g_currentLine][g_lines[g_currentLine].Count - 1] != '\n') {
                g_lines[g_currentLine].Add('\n');
            }

            newLine.Add('\n');

            g_lines.Insert(g_currentLine, newLine);

            ++g_currentLine;
            g_currentCol = -1;

            Print();
        }

        static void RemoveLine()
        {
            g_lines.RemoveAt(g_currentLine--);
            g_currentCol = g_lines[g_currentLine].Count - 2;
            if(g_currentCol < -1) g_currentCol = -1;
        }
    }
}
