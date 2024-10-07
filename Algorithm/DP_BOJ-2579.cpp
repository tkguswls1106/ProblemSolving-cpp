#include <iostream>
#include <algorithm>

using namespace std;

// - 풀이 및 점화식 도출 방법:
// * 과정 1. DP테이블 정의하기:
// dp[i][?]는 i번째 계단까지 밟았을때의 최댓값을 의미. (참고로 i번째 계단은 반드시 밟아야함)
// * 과정 2. 점화식 찾기:
// dp[i][?] = stair[i] + '이전계단꺼인 dp[i-1] or dp[i-2] 를 활용'
// dp[i][2]는 dp[i-1]에 대하여 dp[i-1][1]만 필요로한다. => 'dp[i][2] = stair[i] + dp[i-1][1]'
// dp[i][1]는 dp[i-2]에 대하여 dp[i-2][1]와 dp[i-2][2] 둘중 하나를 필요로한다. => 'dp[i][1] = stair[i] + max(dp[i-2][1], dp[i-2][2])'
// ==> max(dp[i][2], dp[i][1]) 이 답임.
// * 과정 3. 초기값 정의하기:
// dp[3][?]을 구하기위해서는 dp[2][1]와 dp[1][1]와 dp[1][2]이 필요함. (하지만 dp[2][2]까지 초기값을 셋팅해주어야함)

// - 번외(다른 점화식 도출 풀이방식):
// 1. 마지막 계단에서 한칸 내려가는 경우:
// step1 = stair[i] + stair[i - 1] + dp[i - 3]
// 2.마지막 계단에서 두칸을 내려가는 경우:
// step2 = stair[i] + dp[i - 2]
// ==> dp[i] = max(step1, step2)

int stair[302] = { 0, };
int dp[302][3] = { 0, };  // [3]의 인덱스는 1~2으로, 본인계단을 포함하여 연속으로 몇계단째 밟았는지에 대한 값을 의미한다. 어차피 3연속은 안된다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> stair[i];
    }

    // 초기값 할당
    dp[1][1] = stair[1];
    dp[1][2] = 0;  // 방법 없음.
    dp[2][1] = stair[2];
    dp[2][2] = stair[2] + dp[1][1];  // 이거까지 해야 제대로 결과가 나온다.

    // dp배열값 할당
    for(int i=3; i<=n; i++) {
        dp[i][2] = stair[i] + dp[i-1][1];
        dp[i][1] = stair[i] + max(dp[i-2][1], dp[i-2][2]);
    }

    int answer = max(dp[n][2], dp[n][1]);
    cout << answer;


    return 0;
}