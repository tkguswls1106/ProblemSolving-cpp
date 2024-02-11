// - DP '피보나치 수열' 문제 (바텀업 방식) -
// 이처럼 탑다운보단 바텀업 방식을 좀더 추천한다.

#include <iostream>
#include <algorithm>

using namespace std;

// 참고로 이 문제에서는
// '0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. n이 주어졌을 때, n번째 피보나치 수를 구하라.'
// 라고 명시되어있으므로, dp[0]=0 으로 작성해도 좋다.

long long dp[92] = { 0, };  // 피보나치 수열은 N이 커질수록 값이 급속도로 증가하므로 자료형을 long long으로 사용해야한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // DP 점화식 초기값 할당.
    // 피보나치의 경우에는, 점화식이 'DP[i] = DP[i-1] + DP[i-2]'로써 두가지의 초기값 할당이 필요하다.
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {  // DP 테이블에 미리 값을 채워줌. (바텀업 방식이므로 재귀함수 대신 반복문 사용으로 미리 값들을 세팅)
        dp[i] = dp[i-1] + dp[i-2];  // 'DP[i] = DP[i-2] + DP[i-1]'로 생각하면 더 편할지도.
    }

    cout << dp[n];


    return 0;
}