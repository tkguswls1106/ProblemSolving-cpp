#include <string>
#include <vector>

using namespace std;

// 점화식 : dp[i] = dp[i-1] + dp[i-2]

long long dp[100002] = { 0, };

int solution(int n) {
    
    // dp 초기값 할당
    dp[0] = 0;
    dp[1] = 1;
    
    // 바텀업
    for(int i=2; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    return dp[n];
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}