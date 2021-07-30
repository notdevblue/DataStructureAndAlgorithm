// 20219 한우엽

using System;
using System.Collections.Generic;

namespace _730Algo
{
    class Program
    {
        class SecondClass
        {
            public int[] P6(int num1, int num2)
            {
                if (num1 > num2)
                {
                    // num2 가 더 커야 합니다.
                    return null;
                }

                // 도움 받은 출처들
                // 기반: https://funfunhanblog.tistory.com/281 (HJH0825 블로그)
                // 공식: https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95 (위키피디아 유클리드 호제법)
                //       https://mathbang.net/206 (수학방)

                int n1 = num1;
                int n2 = num2;
                
                int   n      = -1;
                int[] answer = new int[2];

                while (n != 0)
                {
                    n  = n2 % n1;
                    n2 = n1;
                    n1 = n;
                }

                Console.WriteLine(n2); // 최대공약수
                // A * B = L * G
                // L = (A * B) / G

                answer[0] = n2;
                answer[1] = num1 * num2 / n2;

                Console.WriteLine("P6: " + answer[0]);
                Console.WriteLine("P6: " + answer[1]);

                return answer;
            }

            public List<int> P7(int x, int n)
            {
                List<int> sum   = new List<int>();
                int       begin = x;

                for (int i = 0; i < n; ++i)
                {
                    sum.Add(begin + x * (i + 1));
                }

                return sum;
            }

            // static 함수 안 변수 기능이 C#에 없어서
            // *슬픈 우앱 움짤 여기에 삽입*

            private int count = 0;
            public int P8(int num)
            {
                if (num < 0) return -1;

                bool isEven = num % 2 == 0;


                if (num == 1)     return count;
                if (count >= 500) return -1;

                ++count;

                switch (isEven)
                {
                    case true:
                        P8(num / 2);
                        break;

                    case false:
                        P8(num * 3 + 1);
                        break;
                }

                return count == 500 ? -1 : count;
            }

            public ulong P9(ulong num)
            {
                int digit = GetDigit(num);
                List<ulong> arr = new List<ulong>();

                SetArr();
                arr.Sort((x, y) => y.CompareTo(x));

                return ListToLong();
                
                #region Function

                int GetDigit(ulong n)
                {
                    int dig = 1;

                    while (true)
                    {
                        n /= 10;
                        if (n == 0)
                        {
                            return dig;
                        }
                        ++dig;
                    }
                }
                void SetArr()
                {
                    for (int i = 0; i < digit; ++i)
                    {
                        arr.Add(num % 10);
                        num /= 10;
                    }
                }
                ulong ListToLong()
                {
                    ulong returnNum = 0;

                    for (int i = digit; i > 0; --i)
                    {
                        returnNum += arr[digit - i] * (ulong)Math.Pow(10, i);
                    }

                    return returnNum / 10;
                }

                #endregion

            }

            public int[] P10(int n)
            {
                int dig   = GetDigit(n);
                int[] arr = new int[dig];
                
                SetArr();

                return arr;

                int GetDigit(int num)
                {
                    int digit = 1;

                    while (true)
                    {
                        num /= 10;
                        if (num == 0)
                        {
                            return digit;
                        }
                        ++digit;
                    }
                }
                void SetArr()
                {
                    for (int i = 0; i < dig; ++i)
                    {
                        arr[i] = (n % 10);
                        n /= 10;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            SecondClass sc = new SecondClass();

            // P6
            sc.P6(3, 12);

            // P7
            List<int> list = new List<int>();
                      list = sc.P7(2, 10);

            foreach (int item in list)
            {
                Console.WriteLine("List: " + item);
            }
            Console.WriteLine();

            // P8
            Console.WriteLine(sc.P8(20040225));
            Console.WriteLine();
            
            // P9
            Console.WriteLine(sc.P9(1789134502345L));
            Console.WriteLine();

            // P10
            int[] arr = new int[sc.P10(1234567).Length];
                  arr = sc.P10(1234567);

            foreach (int item in arr)
            {
                Console.Write(item);
            }
            Console.WriteLine();


        }
    }
}
