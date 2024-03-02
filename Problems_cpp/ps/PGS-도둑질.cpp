#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 백준 1149번 문제인 DP_RGB거리 문제와 아주약간 유사하다 생각됨.
// 참고로 이 문제는 반드시 dp를 첫번째집을 훔쳤을때와 아닐때로 나누어서 풀이해야만 한다.

// - 시간초과 dp식 풀이법:
// dp[a][0] = a위치의 집을 훔치지않았을때, dp[a][1] = a위치의 집을 훔쳤을때
// - 정상동작 dp식 풀이법:
// 'x-1번째 값을 선택하는 경우의 수'를 따지거나. 'x-2번째와 x번째를 선택하는 경우의 수' 이 두가지를 고려할것.
// 그렇다면 dp를 1차원 배열로 두고, 의미는 'dp[i] = i인덱스를 포함해서 여기까지 돈훔쳤을때 총합계'를 의미함.

int dp0[1000002] = { 0, };  // 첫번째집을 훔치지않았을때의 dp
int dp1[1000002] = { 0, };  // 첫번째집을 훔쳤을때의 dp

int solution(vector<int> money) {
    
    dp0[0] = 0, dp0[1] = money[1];
    dp1[0] = money[0], dp1[1] = money[0];  // 첫번째집은 무조건 훔쳐야하므로, 두번째집은 훔치면 안된다.
    
    for(int i=2; i<money.size(); i++) {
        dp0[i] = max(dp0[i-1], dp0[i-2]+money[i]);
        dp1[i] = max(dp1[i-1], dp1[i-2]+money[i]);
    }
    
    int a = dp0[money.size()-1];  // 첫번째집을 훔치지않았을때의 돈합계
    int b = dp1[money.size()-1-1];  // 첫번째집을 훔쳤을때의 돈합계
    
    return max(a,b);
}

int main()
{
    vector<int> money = {1,2,3,1};

    int answer = solution(money);

    cout << answer << "\n";  // => 4 출력


    return 0;
}