#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int t;
int m,n,k;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// 매번 새로운 테스트케이스마다 다시 초기화 해주어야할 변수들
int board[52][52] = { 0, };
int visited[52][52] = { 0, };
int cnt = 0;

queue<pair<int,int>> qu;  // 어차피 큐는 bfs함수에서 마지막에 empty 된 상태로 나오기때문에, 재초기화 해줄 필요없다.

void bfs(int a, int b) {
    if(board[a][b] == 0 || visited[a][b] == 1) return;
    qu.push({a, b});
    visited[a][b] = 1;

    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || visited[nx][ny] == 1) continue;

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

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> m >> n >> k;
        
        for(int j=0; j<k; j++) {
            int x,y;  // 문제에서는 x가 m관련이고 y가 n관련이므로, 실제로 입력받을때는 x가 n으로 y과 m으로 할당하여 반대로 입력받아야한다.
            cin >> y >> x;  // 문제에서는 x 다음 y 순으로 입력해주므로, 반대로 난 y 다음 x 순으로 할당해주면 된다.
            board[x][y] = 1;
        }

        for(int q=0; q<n; q++) {
            for(int w=0; w<m; w++) {
                bfs(q,w);
            }
        }
        cout << cnt << "\n";

        // 변수들 재초기화
        fill(&board[0][0], &board[n-1][m-1+1], 0);
        fill(&visited[0][0], &visited[n-1][m-1+1], 0);
        cnt = 0;
    }


    return 0;
}