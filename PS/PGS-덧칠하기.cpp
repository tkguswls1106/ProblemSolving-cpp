#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int sec = section[0];  // 첫구역
    int cnt = 1;  // 적어도 한번이상은 칠하고 시작하므로, cnt는 1부터 시작.
    
    for(int i=1; i<section.size(); i++) {
        if(sec + m <= section[i]) {  // 첫구역 + 롤러길이 <= 다음구역
            cnt++;
            sec = section[i];
        }
    }
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}