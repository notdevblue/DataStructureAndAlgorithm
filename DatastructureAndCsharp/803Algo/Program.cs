using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;

namespace _803Algo
{
    class Program
    {
        class Mandu
        {
            public int P11(int n)
            {
                string str = n.ToString();
                int result = 0;

                for (int i = 0; i < str.Length; ++i)
                {;
                    result += (str[i] - '0');
                }

                return result;
            }

            public int P12(int a, int b)
            {
                int result = 0;

                for (int begin = (a > b ? b : a); begin <= (a > b ? a : b); ++begin)
                {
                    result += begin;
                }

                return result;
            }

            public string P13(string s, int n)
            {
                List<char> ch = s.ToList();

                for (int i = 0; i < ch.Count; ++i)
                {
                    if (ch[i] == ' ')
                    {
                        continue;
                    }

                    if (ch[i] >= 'a' && ch[i] <= 'z')
                    {
                        ch[i] = (ch[i] + n > 'z') ? (char)(ch[i] + n - 'z' + 'a' - 1) : (char)(ch[i] + n);
                    }
                    else
                    {
                        ch[i] = (ch[i] + n > 'Z') ? (char)(ch[i] + n - 'Z' + 'A' - 1) : (char)(ch[i] + n);
                    }
                }

                return new string(ch.ToArray());
               
            }

            public int P14(string s)
            {
                return int.Parse(s);
            }

            public string P15(int n)
            {
                StringBuilder str = new StringBuilder();

                for (int i = 0; i < n; ++i)
                {
                    str.Append(i % 2 == 0 ? "환" : "쥬");
                }

                return str.ToString();
            }
        }

        static void Main(string[] args)
        {
            Mandu mandu = new Mandu();

            Console.WriteLine(mandu.P11(20040225));
            Console.WriteLine(mandu.P12(3, 2));
            Console.WriteLine(mandu.P13("wa sans asinunguna", 15));
            Console.WriteLine(mandu.P14("-123"));
            Console.WriteLine(mandu.P15(10));

        }
    }
}
