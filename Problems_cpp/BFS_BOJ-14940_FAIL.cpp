// < 시간초과 FAIL 코드 >
// - 놓쳤던 부분:
// 답은 맞게나온다. 하지만 이 코드처럼 모든 좌표에서 bfs를 돌리는 방식을 사용하게되면,
// 시간복잡도가 오래걸리게되어, 문제의 조건인 '시간제한이 1초이고, N과 M이 1000까지 올라가야함'에 어울리지 않는 코드가 된다.
// - 해결 방법:
// 발상을 전환하여, 기존처럼 '모든 좌표에서의 목표도착지점까지의 거리를 구하는 방식'이 아니라, '목표도착지점에서 출발한 모든 좌표까지의 거리를 구하는 방식'으로 풀면 된다.

#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, goalX, goalY;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[1002][1002] = { 0, };
int dist[1002][1002] = { 0, };

void bfs(int x, int y) {
    if(board[x][y] == 0 || dist[x][y] > 0) return;

    queue<pair<int,int>> qu;
    qu.push({x,y});
    dist[x][y] = 1;

    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || dist[nx][ny] > 0) continue;

            qu.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                goalX = i;
                goalY = j;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            bfs(i,j);  // {i,j} 좌표는 출발지점을 의미함. 

            if(board[i][j] == 2 || board[i][j] == 0) {  // '출발지점이 애초에 목표도착지점일 경우' 또는 '애초에 출발지점이 막혀있는 경우'
                cout << 0 << " ";
            }
            else {  // 출발지점 board값이 1로 출발할 수 있는 경우
                if(dist[goalX][goalY] == 0)  // 출발은 했지만, 막상 목표도착지점에 못닿았을경우(dist=0)
                    cout << -1 << " ";
                else  // 출발해서 목표도착지점 도달에 성공한경우
                    cout << dist[goalX][goalY] - 1 << " ";  // 애초에 출발지점부터 dist=1로 지정해주었기에, 차후에 출력할때는 -1로 빼준상태로 출력해주어야한다.
            }

            fill(&dist[0][0], &dist[n-1][m], 0);
        }
        cout << "\n";
    }


    return 0;
}