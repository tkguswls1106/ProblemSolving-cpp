// - DP '누적 합' 문제 -

#include <iostream>

using namespace std;

// - 알고리즘 결정하는 과정:
// 이 문제는 일반적인 구현으로도 풀수는 있지만,
// 시간제한이 1초인 반면, N과 M의 최댓값이 각각 100000이라서, 구현으로 풀게되면 O(NM=100억)까지 시간복잡도가 나올수있어 구현 방식으로 풀면 안된다.
// 그러므로, DP를 활용한 누적합(Prefix sum) 알고리즘으로 풀어야만 한다.

// - 1. DP테이블 정의:
// dp[i] = arr[1]부터 arr[i]까지 더한 합계를 의미.
// - 2. 점화식 도출:
// 'dp[i] = arr[1]부터 arr[i]까지 더한 합계' => 'dp[i] = dp[i-1] + arr[i]'
// 'arr[a] 부터 arr[b]까지 더한 합계' => 'dp[b] - dp[a-1]'
// ==> dp[b] - dp[a-1]
// - 3. dp[2]를 구하기위한 초기값 정의:
// dp[1] 필요함.

int arr[100002] = { 0, };
int dp[100002] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];  // 초기값 할당

    // dp배열값 할당
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + arr[i];
    }

    while(m--) {
        int i,j;
        cin >> i >> j;

        cout << dp[j] - dp[i-1] << "\n";
    }


    return 0;
}