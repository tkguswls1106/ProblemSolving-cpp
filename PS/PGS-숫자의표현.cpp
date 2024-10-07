#include <vector>

using namespace std;

// 10000 * 10000 = 1억 => for문 범위생각하면 1억번 미만 소요 => 중첩for문 사용하여도 시간복잡도 빠름.

int solution(int n) {
    int cnt = 1;  // i==n일때를 포함한 카운팅 시작.
    for(int i=1; i<=n-1; i++) {
        int sum = i;
        for(int j=i+1; j<=n; j++) {
            sum += j;
            if(sum == n) {
                cnt++;
                break;
            }
            else if(sum > n) break;
        }
    }
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}