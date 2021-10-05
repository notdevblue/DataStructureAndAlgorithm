#include <stdio.h>
#include <vector>

#define BLANK '0'
#define QUEEN 'Q'

std::vector<std::vector<char>> solution(int n);

int main()
{
  for(auto&& i : solution(8))
  {
    for(char j : i)
    {
      printf("%c", j);
    }
    printf("\n");
  }
}


std::vector<std::vector<char>> solution(int n)
{
    std::vector<std::vector<char>> answer(std::vector(n, std::vector(n, BLANK)));

    bool isOdd = n & 1;
    n = isOdd ? n - 1 : n;

    int quaterN = n / 4;
    int halfN = n / 2;

    // y = x/2;
    
    answer[0][halfN] = QUEEN;
    answer[quaterN][0] = QUEEN;


    if(n >= 8)
    {
        for(int i = 0; i < halfN - 1; ++++i)
        {
            answer[quaterN - i / 2][i] = QUEEN;
            answer[halfN - i / 2][halfN + i] = QUEEN;
        }
    }

    for(int i = 0; i < halfN; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            answer[n - 1 - i][n - 1 - j] = answer[i][j];
        }
    }

    if(isOdd)
    {
      for(int i = 0; i < n; ++i)
      {
        answer[i][n] = BLANK;
        answer[n][i] = BLANK;
      }
      answer[n][n] = QUEEN;
    }

    return answer;

}
