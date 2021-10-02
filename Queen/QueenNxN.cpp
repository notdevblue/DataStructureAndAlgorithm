// 20219 한우엽
// 만약에 결과가 정상적이지 않다면 g++로 컴파일 후 실행해 주세요.
#include <iostream>
#include <string>
#include <vector>

#define BLANK_SPACE '-'
#define QUEEN 'Q'

std::vector<std::vector<char>> solution(int n);

int main()
{
    int input;

    std::cout << "input: ";
    std::cin >> input;

    for (auto &&i : solution(input))
    {
        for(auto &&j : i)
        {
            std::cout << j;
        } // for(auto &&j : i) => i is solution(n)[i] => is vector<char>; end

        std::cout << "\n";
    } // for(auto &&i : solution(n)); end

    return (0);
} // main(); end

std::vector<std::vector<char>> solution(int n)
{
    if (n < 4) // Exception
    {
        std::cerr << "n should be euqal or bigger than 4.\r\ninput: " << n << std::endl;
        throw;
    } // Exception end

    std::vector<std::vector<char>> answer(n, std::vector<char>(n, BLANK_SPACE));

    bool isOdd = n & 1 == 1;

    n = isOdd ? n - 1 : n; // for last corner output

#pragma region for optimization
    int quaterN = n / 4;
    int halfN = n / 2;

    int i;
    int halfI;
    int j;

    int row;
    int nRevLoop = n - 1;
#pragma endregion // for optimization


    answer[0][halfN] = QUEEN;
    answer[quaterN][0] = QUEEN;

    if(n >= 8)
    {
        for (i = 0; i < halfN - 1; ++++i)
        {
            halfI = i / 2;

            answer[quaterN - halfI][i] = QUEEN;
            answer[halfN - halfI][halfN + i] = QUEEN;

        } // for(i = 0; i < halfN - 1; ++++i) => halfN is n / 2; end
    }

    for (i = 0; i < halfN; ++i)
    {
        row = nRevLoop - i;

        for (j = 0; j < n; ++j)
        {
            answer[row][nRevLoop - j] = answer[i][j]; // row is nRevLoop - i => nRevLoop is n - 1;
        } // for(j = 0; j < n; ++j); end

    } // for(i = 0; i < halfN; ++i) => halfN is n / 2; end

    if(isOdd)
    {
        for (i = 0; i < n - 1; ++i)
        {
            answer[i][n] = BLANK_SPACE;
            answer[n][i] = BLANK_SPACE;
        }

        answer[n][n] = QUEEN;

    } // if(isOdd) end

    return answer;
} // solution(int n); end