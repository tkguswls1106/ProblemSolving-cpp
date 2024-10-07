#include <vector>

// 점화식: dp[i] = dp[i-1] + dp[i-2]

using namespace std;

long long solution(int n) {
    long long dp[2010] = { 0, };
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    return dp[n];
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}