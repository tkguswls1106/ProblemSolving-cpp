#include <vector>

using namespace std;

// 어차피 전체수가 최대 200만5천 이하이므로, 중첩 for문으로 풀기 가능.
// 1. 전체가로 >= 전체세로
// 2. 전체세로 x 전체가로 = 전체갈색수 + 전체노랑수
// 3. 전체노랑수 = (전체세로 - 2) x (전체가로 - 2)
// = (전체세로 x 전체가로) -2(x전체세로) -2(x전체가로) +4
// = 전체수 + 4 - 2 x (전체세로 + 전체가로)
// ==> 2 x (전체세로 + 전체가로) = 전체수 + 4 - 전체노랑수
// ==> 전체세로 + 전체가로 = (전체수 + 4 - 전체노랑수) / 2 = (전체갈색수 + 4) / 2

vector<int> solution(int brown, int yellow) {
    int x, y;  // 전체세로, 전체가로 (n,m)
    // 1. y >= x
    // 2. x * y == brown + yellow
    // 3. x + y == (brown + 4) / 2
    for(int x=3; x<=2005000/3; x++) {
        for (int y=x; x*y<=2005000; y++) {
            if(x * y == brown + yellow && x + y == (brown + 4) / 2) return {y,x};
        }
    }
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}