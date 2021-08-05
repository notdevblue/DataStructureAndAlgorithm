// 20219 한우엽
using System;
using System.Linq;
using System.Text;
using System.Collections.Generic;

namespace _805Algo
{
    class Program
    {
        class ManduSecond
        {
            public int P16(int n)
            {
                if (n <= 1) return 0;

                bool isPrime = true;
                int primeCount = 0;

                // 별로 좋은 코드는 아닌 듯 함미다
                // % 연산자 츄라이
                // i ~ n
                for (int i = 2; i <= n; ++i)
                {
                    for (int j = 2; j < i; ++j)
                    {
                        if (i % j == 0)
                        {
                            isPrime = false;
                        }
                    }

                    primeCount = isPrime ? primeCount + 1 : primeCount;
                    isPrime = true;
                }

                return primeCount;
            }

            public bool P17(string s)
            {
                if (s.Length == 0b0000_0100 || s.Length == 0b0000_0110)
                {
                    for (int i = 0b0000_0000; i < s.Length; i = i + 0b0000_0001)
                    {
                        if (s[i] < 0b0011_0000 || s[i] > 0b0011_1001)
                        {
                            return bool.Parse("false");
                        }
                    }

                    return bool.Parse("true");
                }
                else
                {
                    return bool.Parse("false");
                }
            }

            public string P18(string s)
            {
                StringBuilder sb = new StringBuilder();

                if (s.Length % 2 == 0)
                {
                    sb.Append(s[s.Length / 2 - 1]);
                }
                sb.Append(s[s.Length / 2]);

                return sb.ToString();
            }

            public string P19(string s)
            {
                List<char> list = new List<char>();
                list = s.ToList();

                list.Sort((x, y) => y.CompareTo(x));

                return new string(list.ToArray());
            }


            /// <returns>null when Exception</returns>
            public List<string> P20(List<string> strings, int n)
            {
                bool isException = false;
                
                strings.Sort((x, y) =>
                {
                    isException = x.Length <= n;
                    if (!isException)
                    {
                        return x[n].CompareTo(y[n]);
                    }
                    return 0;
                });

                if (isException) return null;

                return strings;
            }
        }

        static void Main(string[] args)
        {
            ManduSecond mandu = new ManduSecond();

            List<string> strings =
                new List<string>() { "Han", "Jan", "San", "Bek", "Sun", "Wan", "Dim", "Sum" };

            Console.WriteLine(mandu.P16(10));
            Console.WriteLine(mandu.P17("1234"));
            Console.WriteLine(mandu.P18("Jwan"));
            Console.WriteLine(mandu.P19("abcdefg"));
            mandu.P20(strings, 1)?.ForEach(c => Console.Write($"{c} "));
        }
    }
}
