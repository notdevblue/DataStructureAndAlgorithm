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

                for (int i = 0; i < numbers.Length; ++i)
                {
                    for (int j = i + 1; j < numbers.Length; ++j)
                    {
                        numberList.Add(numbers[i] + numbers[j]);
                    }
                }
                
                return numberList.OrderBy(x => x).Distinct().ToArray();
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
                return new DateTime(2024, a, b).DayOfWeek.ToString().Substring(0, 3).ToUpper();
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
                
                int maxIdx = -1;
                int minIdx = -1;
                int midIdx = -1;
                int max = int.MinValue;
                int min = int.MaxValue;

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

                for (int i = 0; i < correctAns.Count; ++i)
                {
                    if (maxIdx != i && minIdx != i)
                    {
                        midIdx = i;
                        break;
                    }
                }
                
                string[] nameData = new string[3] { "수포자 1", "수포자 2", "수포자 3" };
                List<string> names = new List<string>() { nameData[maxIdx], nameData[midIdx], nameData[minIdx] };

                return names.ToArray();
            }

            public int P25(int n, int[] lost, int[] reserve)
            {
                int canPE = n - lost.Length;

                for (int i = 0; i < lost.Length; ++i)
                {
                    for (int j = 0; j < reserve.Length; ++j)
                    {
                        if ((lost[i] == reserve[j]) || (reserve[j] - 1 > 0 && lost[i] == reserve[j] - 1) || (reserve[j] + 1 <= n && lost[i] == reserve[j] + 1))
                        {
                            ++canPE;
                        }
                    }
                }

                return canPE;
            }

            public int P26(string s)
            {
                StringBuilder sb = new StringBuilder();
                StringBuilder tempsb = new StringBuilder();
                string[] textnumbers = new string[] { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

                for (int i = 0; i < s.Length; ++i)
                {
                    if (int.TryParse(s[i].ToString(), out int temp))
                    {
                        sb.Append(s[i]);
                        tempsb.Remove(0, tempsb.Length);
                        continue;
                    }

                    tempsb.Append(s[i]);

                    for (int j = 0; j < 10; ++j)
                    {
                        if (tempsb.ToString() == textnumbers[j])
                        {
                            tempsb.Remove(0, tempsb.Length);
                            sb.Append(j);
                            break;
                        }
                    }
                }

                return int.Parse(sb.ToString());
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


            mandu.P24(new int[] { 3, 3, 1, 1, 5, 1, 2, 3, 3, 4, 1, 2, 2, 2, 1, 3, 4, 1, 2, 4 }).ToList().ForEach(e =>
            {
                Console.WriteLine(e);
            });
            Console.WriteLine();

            Console.WriteLine(mandu.P25(20, new int[] { 1, 4, 5, 7, 11 }, new int[] { 2, 5, 7, 9 }));
            Console.WriteLine();

            Console.WriteLine(mandu.P26("onefive4"));
            Console.WriteLine();
        }
    }
}
