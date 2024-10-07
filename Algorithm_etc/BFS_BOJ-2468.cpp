#include <queue>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[102][102] = { 0, };
int visited[102][102] = { 0, };
queue<pair<int,int>> qu;
set<int> s;

int n;

int maxCnt = 1;  // 잠길높이가 0인경우를 대비해서 미리 1로 초기화시켜 대입해둠.
int cnt = 0;
void bfs(int x, int y, int limit) {
    if(board[x][y] <= limit || visited[x][y] == 1) return;

    qu.push({x,y});
    visited[x][y] = 1;

    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] <= limit || visited[nx][ny] == 1) continue;

            qu.push({nx,ny});
            visited[nx][ny] = 1;
        }
    }

    cnt++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            s.insert(board[i][j]);
        }
    }

    for(auto iter=s.begin(); iter!=s.end(); iter++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                bfs(i, j, *iter);
            }
        }
        maxCnt = max(maxCnt, cnt);

        // 재초기화
        fill(&visited[0][0], &visited[n-1][n], 0);
        cnt = 0;
    }
    
    cout << maxCnt;


    return 0;
}