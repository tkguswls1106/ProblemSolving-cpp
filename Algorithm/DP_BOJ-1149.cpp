#include <iostream>
#include <algorithm>

using namespace std;

// - 1. DP테이블 정의:
// dp[i][0] = i번째 집까지 칠할때의 최솟값을 의미. (단, i번째집은 R빨강)
// dp[i][1] = " (단, i번째집은 G초록)
// dp[i][2] = " (단, i번째집은 B파랑)
// - 2. 점화식 도출:
// dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0]
// dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1]
// dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2]
// ==> min({dp[i][0], dp[i][1], dp[i][2]}) 가 답임.
// - 3. dp[2][?]을 구하기위한 초기값 정의:
// dp[1][0], dp[1][1], dp[1][2] 필요함.

int dp[1002][3] = { 0, };
int rgb[1002][3] = { 0, };  // 0: R, 1: G, 2: B

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    // 초기값 할당
    dp[1][0] = rgb[1][0];
    dp[1][1] = rgb[1][1];
    dp[1][2] = rgb[1][2];

    // dp배열값 할당
    for(int i=2; i<=n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]});


    return 0;
}