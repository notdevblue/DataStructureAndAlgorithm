using System;
using System.Linq;

namespace _812Algo
{
    class Program
    {
        public class ManduFourth
        {
            // 후후 한줄 후후
            public string P1(string s)
            {
                return string.Join(" ",
                    from word in s.Split(' ').ToList()
                    select word[0].ToString().ToUpper() + word[1..].ToLower()
                    );
            }

            public int P3(int[] prices)
            {
                int upGoingSec = 0;
                for (int i = 1; i < prices.Length; ++i)
                {
                    upGoingSec += prices[i] >= prices[i - 1] ? 1 : 0;
                }

                return upGoingSec;
            }

        }

        static void Main(string[] args)
        {
            ManduFourth mandu = new ManduFourth();

            Console.WriteLine(mandu.P1("lOrEn iPSUM dOlor siT amEt"));
            Console.WriteLine(mandu.P3(new int[] { 12345,34567,1345,3567,1235,4567,234,3567,1234,4567123,4567,567,23456,12,3567,23,567,132,7356,132,4567,123,4567,3124,3457,3456,3567,2346,2456,3467,4568,2456,46789 }));

        }
    }
}
