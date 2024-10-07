// - BFS 미로(2차원) 문제 -

#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dist;  // 거리 배열 distance
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int x, int y) {
    if(board[x][y] == 0 || dist[x][y] > 0) return;

    queue<pair<int, int>> qu;
    qu.push({x,y});
    dist[x][y] = 1;  // 이 문제의 경우에는 처음 시작거리를 1부터 스타트해야함.

    while(!qu.empty()) {
        pair<int, int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            if(board[nx][ny] == 0 || dist[nx][ny] > 0) continue;

            qu.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;  // 주변좌표의 거리값 = 기준좌표 거리값 + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m));

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            board[i][j] = str[j] - '0';  // char to int
        }
    }

    bfs(0, 0);  // 이 문제의 경우에는, 어차피 미로로 쭉 경로가 끊기지않고 이어져있으므로 bfs함수를 for문으로 여러번 호출해줄필요가 없다.

    cout << dist[n-1][m-1];


    return 0;
}