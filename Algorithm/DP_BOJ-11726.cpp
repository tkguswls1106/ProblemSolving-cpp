#include <iostream>

using namespace std;

// - 1. DP테이블 정의:
// dp[i] = 2xi 크기의 직사각형을 채우는 방법의 수
// - 2. 점화식 도출:
// 첫번째 세로줄을 채우려면 '세로로긴 직사각형 1개로 채우는법'과 '가로로긴 직사각형 2개로 채우는법'이 있다.
// 전자는 한줄이 채워지므로 남은 줄은 dp[i-1]이고, 후자는 두줄이 채워지므로 남은 줄은 dp[i-2]가 된다.
// ==> 그렇다면, dp[i] = dp[i-1] + dp[i-2] 이다.
// - 3. dp[3]을 구하기위한 초기값 정의:
// dp[2], dp[1] 필요함.

int dp[1002] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 초기값 할당
    dp[1] = 1;
    dp[2] = 2;

    // dp배열값 할당
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;  // 주의사항: 만약 여기서 10007 연산을 해주지않고, 출력문에만 넣어준다면, dp배열내부값이 너무커져서 int를 초과할 수 있다.
    }

    cout << dp[n];  // 만약 여기서 연산 후 출력해줄 경우, 마찬가지로 여기서도 10007 연산을 해주어야 한다.


    return 0;
}