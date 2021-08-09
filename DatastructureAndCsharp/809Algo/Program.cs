using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace _809Algo
{
    class Program
    {
        class ManduThird
        {
            public int[] P21(int[] numbers) // 음
            {
                List<int> numberList = new List<int>();
                int sum;

                for (int i = 0; i < numbers.Length; ++i)
                {
                    sum = 0;

                    for (int j = i + 1; j < numbers.Length; ++j)
                    {
                        numberList.Add(numbers[i] + numbers[j]);
                    }
                }

                numberList.Sort();

                return numberList.ToArray();
            }

            public string P22(string s)
            {
                StringBuilder sb = new StringBuilder();
                int decideUpper = 0;

                for (int i = 0; i < s.Length; ++i)
                {
                    decideUpper = s[i] == ' ' ? 0 : decideUpper;

                    sb.Append(i % 2 == 0 ? s[i].ToString().ToUpper() : s[i].ToString().ToLower());
                    ++decideUpper;
                }

                return sb.ToString();
            }

            public string P23(int a, int b)
            {
                DateTime date = new DateTime(2024, a, b);
                string[] days = new string[] { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
                
                return days[(int)date.DayOfWeek];
            }

            public string[] P24(int[] answers)
            {
                int[] supo1Answer = new int[] { 1, 2, 3, 4, 5 };
                int[] supo2Answer = new int[] { 2, 1, 2, 3, 2, 4, 2, 5 };
                int[] supo3Answer = new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
                List<int> correctAns = new List<int>() { 0, 0, 0 };

                for (int i = 0; i < answers.Length; ++i)
                {
                    correctAns[0] = supo1Answer[i % supo1Answer.Length] == answers[i] ? correctAns[0] + 1 : correctAns[0];
                    correctAns[1] = supo2Answer[i % supo2Answer.Length] == answers[i] ? correctAns[1] + 1 : correctAns[1];
                    correctAns[2] = supo3Answer[i % supo3Answer.Length] == answers[i] ? correctAns[2] + 1 : correctAns[2];
                }

                int maxIdx;
                int max = int.MaxValue;
                int minIdx;
                int min = int.MinValue;

                for (int i = 0; i < correctAns.Count; ++i)
                {
                    if (max <= correctAns[i])
                    {
                        max = correctAns[i];
                        maxIdx = i;
                    }
                    if (min >= correctAns[i])
                    {
                        min = correctAns[i];
                        minIdx = i;
                    }
                }

                string[] names = new string[] { "수포자1", "수포자2", "수포자3" };
            
                // string 으로 념겨주는것

                return null;
            }

            public int P25(int n, int[] lost, int[] reserve)
            {


                return -1;
            }

            public int P26(string s)
            {



                return -1;
            }
        }

        static void Main(string[] args)
        {
            ManduThird mandu = new ManduThird();

            mandu.P21(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }).ToList().ForEach(e =>
            {
                Console.Write($"{e} ");
            });

            Console.WriteLine();

            Console.WriteLine(mandu.P22("Han Woo Yeop"));

            Console.WriteLine();

            Console.WriteLine(mandu.P23(6, 5));

            Console.WriteLine();

            Console.WriteLine(mandu.P24(new int[] { 3, 3, 1, 1, 5, 1, 2, 3, 3, 4, 1, 2, 2, 2, 1, 3, 4, 1, 2, 4 }));
        }
    }
}
