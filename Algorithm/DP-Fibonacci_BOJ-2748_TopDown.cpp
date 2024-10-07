// - DP '피보나치 수열' 문제 (탑다운 방식) -
// 하지만 이와같은 탑다운보단 바텀업 방식을 좀더 추천한다.

#include <iostream>
#include <algorithm>

using namespace std;

// 참고로 이 문제에서는
// '0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. n이 주어졌을 때, n번째 피보나치 수를 구하라.'
// 라고 명시되어있으므로, dp[0]=0 으로 작성해도 좋다.

long long dp[92] = { 0, };  // 피보나치 수열은 N이 커질수록 값이 급속도로 증가하므로 자료형을 long long으로 사용해야한다. 밑의 fibo 재귀함수도 마찬가지다.

long long fibo(int x) {  // 탑다운 방식이므로 반복문 대신 재귀함수 사용. (x는 dp[i]에서의 i라고 생각하면 편하다.)
    // 피보나치의 경우에는, 점화식이 'DP[i] = DP[i-1] + DP[i-2]'로써 두가지의 종료조건은 필요하다.
    if(x == 0) return 0;
    if(x == 1) return 1;

    // 이미 계산한적 있는 문제라면 그대로 반환
    if(dp[x] != 0) return dp[x];

    // 아직 계산하지 않은 문제라면 점화식에 따라서 피보나치 결과 반환
    return dp[x] = fibo(x-1) + fibo(x-2);  // 'dp[i] = fibo(i-2) + fibo(i-1)'로 생각하면 더 편할지도.
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cout << fibo(n);


    return 0;
}