#include <vector>
#include <iostream>

using namespace std;

// 이 문제는 bfs로 풀면 시간초과가 난다.
// 최단경로의 개수를 1,000,000,007로 나눈 나머지 ~~ => DP 사용
// * 점화식: dp[a][b] = dp[a-1][b] + dp[a][b-1]
// * 초기값: dp[1][1] = 1

int dp[102][102] = { 0, };  // 어차피 좌표{0,0}같은 범위초과부분은 0값이므로, dp[1][1]만 초기값 부여해줘도됨.

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for(int i=0; i<puddles.size(); i++) {
        int y = puddles[i][0];
        int x = puddles[i][1];
        dp[x][y] = -1;
    }

    dp[1][1] = 1;  // 집 위치
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i==1 && j==1) continue;
            if(dp[i][j] == -1) continue;
            
            int up=0, left=0;
            if(dp[i-1][j] != -1) up = dp[i-1][j];
            if(dp[i][j-1] != -1) left = dp[i][j-1];
            
            dp[i][j] = (up+left) % 1000000007;
        }
    }
    
    return dp[n][m];
}

int main()
{
    int m = 4, n = 3;
    vector<vector<int>> puddles = {{2, 2}};

    int answer = solution(m, n, puddles);

    cout << answer << "\n";  // => 4 출력


    return 0;
}