#include <vector>
#include <algorithm>

using namespace std;

// 점화식 : dp[i][0] = max(dp[i-1][1], dp[i-1][2], dp[i-1][3]) + land[i][0]
int dp[100002][4] = { 0, };

int solution(vector<vector<int>> land) {
    
    // 초기값 할당
    for(int i=0; i<4; i++) dp[0][i] = land[0][i];
    
    // dp값 할당
    int maxIdx = land.size()-1;
    for(int i=1; i<=maxIdx; i++) {
        for(int j=0; j<4; j++) {
            int maxDP = -1;
            for(int k : {0,1,2,3}) {
                if(j != k) maxDP = max(maxDP, dp[i-1][k]);
            }
            dp[i][j] = maxDP + land[i][j];
        }
    }
    
    return max({dp[maxIdx][0], dp[maxIdx][1], dp[maxIdx][2], dp[maxIdx][3]});
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}