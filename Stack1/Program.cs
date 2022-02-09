// dotnet 6.0의 힘
// 컴파일 에러 안 나고 실행 잘 됨 ㄹㅇㅋㅋ

// const string input = "i ( n { st } al ) l g ( en ( to ) o )";
// const string input = "installGentoo([)]";
// const string input = "(install)[Gentoo";
const string input = "install)Gentoo";

const string brackets = "({[)}]";

int bracketCount = brackets.Length / 2;
int[] bracketStatus = new int[bracketCount];
int[] lastBracketHistory = new int[input.Length];
int historyIndex = 0;

for (int j = 0; j < input.Length; ++j)
{
    for (int i = 0; i < brackets.Length; ++i)
    {
        if (input[j] == brackets[i]) {
            CheckBracketStatus(i);

            if (i >= bracketCount) {
                CheckBracketOrder(i);
            }

            lastBracketHistory[historyIndex++] = i;

            if(i >= bracketCount) {
                --historyIndex;
            }

            
            System.Console.WriteLine();

        }

    }


}

CheckBracketCount();


#region 함수들

void CheckBracketOrder(int index)
{
    historyIndex = historyIndex - 1 < 0 ? 0 : historyIndex - 1;

    if(brackets[lastBracketHistory[historyIndex]] != brackets[index % 3]) throw new Exception("오류: 조건 3 위반");
}

void CheckBracketStatus(int index)
{
    bracketStatus[index % 3] += index >= bracketCount ? -1 : 1;

    if(bracketStatus[index % 3] < 0) throw new Exception("오류: 조건 2 위반");
}

void CheckBracketCount()
{
    for (int i = 0; i < bracketStatus.Length; ++i) {
        if(bracketStatus[i] != 0) throw new Exception("오류: 조건 1 위반");
    }
}

#endregion