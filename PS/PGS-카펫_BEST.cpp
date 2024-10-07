#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int h = 3;  // 전체세로
    int all = brown + yellow;  // 전체수 = 전체갈색수 + 전체노랑수
    
    for(int h=3; h<=all/3; h++) {
        if(all%h != 0) continue;
        int w = all/h;  // 전체가로
        
        // 1. 전체가로 >= 전체세로
        // 2. 전체노랑수 = (전체세로-2) x (전체가로-2)
        if(w >= h && yellow == (h-2)*(w-2)) {
            return {w,h};
        }
    }
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}