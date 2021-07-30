// 20219 한우엽

using System;

namespace DatastructureAndCsharp
{
    class Program
    {
        class FirstClass
        {
            public void PrintStar(int n, int m)
            {
                for (int i = 0; i < m * n; ++i)
                {
                    if (i % n == 0) Console.WriteLine();

                    Console.Write('*');
                }
            }

            public string OddEven(int num)
            {
                if (num == 0) return "Even";
                return num % 2 == 0 ? "Even" : "Odd";
            }

            public string PhoneNumber(string str)
            {
                System.Text.StringBuilder sb = new System.Text.StringBuilder(20, 20);
                System.Text.StringBuilder sbrev = new System.Text.StringBuilder(20, 20);
                for (int i = 0; i < 20; ++i) sbrev.Append(' ');
                

                int coverStart = 4;

                for (int i = str.Length - 1; i >= str.Length - coverStart; --i)
                {
                    sb.Append(str[i]);
                }
                for (int i = str.Length - 1 - coverStart; i >= 0; --i)
                {
                    sb.Append('*');
                }

                // 수업 후 코딩
                // 원레 앞은 그대로 나두고 뒤 4자리를 더하는 방법도 있다
                // SubString() 함수를 사용하는 방법도 있다.
                // 이망할c++


                for (int i = 0; i < str.Length; ++i)
                {
                    sbrev[str.Length - i - 1] = sb[i];
                }
                return sbrev.ToString().TrimEnd();
            }

            // 하은쌤코멘트
            // float 보단 double 을 더 많이 사용함
            // "double" 을 대부분 많이 사용함
            public float Average(int[] arr)
            {
                int sum = 0;

                for (int i = 0; i < arr.Length; ++i)
                {
                    sum += arr[i];
                }

                return (float)sum / arr.Length;
            }

            public int[] EraseLeast(int[] arr)
            {
                if (arr.Length == 1) return new int[1] { -1 };

                int min      = int.MaxValue;
                int minIdx   = 0;
                int[] newArr = new int[arr.Length];

                for (int i = 0; i < arr.Length; ++i)
                {
                    min = min > arr[i] ? arr[i] : min;
                    minIdx = i;
                }

                int j = 0;
                for (int i = 0; i < arr.Length; ++i)
                {
                    if (i != minIdx) ++j;
                    newArr[j] = arr[i];
                }

                return newArr;
            }
        }

        static void Main(string[] args)
        {
            FirstClass fc = new FirstClass();

            int a = 0;
            int b = 0;

            if (!int.TryParse(Console.ReadLine(), out a)) return;
            if (!int.TryParse(Console.ReadLine(), out b)) return;
            fc.PrintStar(a, b);

            Console.WriteLine();

            if (!int.TryParse(Console.ReadLine(), out a)) return;
            Console.WriteLine(fc.OddEven(a));

            Console.WriteLine();

            Console.WriteLine(fc.PhoneNumber("01027544749"));

            Console.WriteLine();

            Console.WriteLine(fc.Average(new int[] { 1, 2, 5, 1, 67, 21, 3, 78 }));

            int[] arr;
            arr = fc.EraseLeast(new int[] {1,2,3,4,5,6,-1,8 });
            
            for (int i = 0; i < arr.Length - 1; ++i)
            {
                Console.Write(arr[i] + " ");
            }
        }
    }
}
