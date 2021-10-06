#include <iostream>
#include <vector>

char BLANK;
char QUEEN;

std::vector<std::vector<char>> solution(int n);

int main(int argc, char** argv)
{
  if(argc > 1 && argc < 4)
  {
    QUEEN = argv[1][0];
    BLANK = argv[2][0];
  }
  else
  {
    std::cout << "USAGE: program QUEEN BLANK" << std::endl;
    return(0);
  }

  int n;
  std::cout << "Input: ";
  std::cin >> n;

  for(auto&& i : solution(n))
  {
    for(char j : i)
    {
      std::cout << j;
    }
    std::cout << "\n";
  }

  return(0);
}


std::vector<std::vector<char>> solution(int n)
{
  std::vector<std::vector<char>> answer(std::vector(n, std::vector(n, BLANK)));
  
  bool isOdd = n & 1;
  n = isOdd ? n - 1 : n;

  int halfN = n / 2;
  int quaterN = n / 4;

  answer[quaterN][0] = QUEEN;
  answer[0][halfN] = QUEEN;

  if(n >= 8)
  {
    for(int i = 0; i < halfN; ++++i) // y = x/2
    {
      answer[quaterN - i / 2][i] = QUEEN;
      answer[halfN - i / 2][halfN + i] = QUEEN;
      // [y][x]
    }
  }

  for(int i = 0; i < halfN; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      answer[n - i - 1][n - j - 1] = answer[i][j];
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
