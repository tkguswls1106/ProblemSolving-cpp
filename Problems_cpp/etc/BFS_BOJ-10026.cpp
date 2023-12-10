#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[102][102] = { 0, };  // R: 0, G: 1, B:2
int visited[102][102] = { 0, };

int cnt1 = 0;  // 적록색약X일때 구역의수 카운트.
int cnt2 = 0;  // 적록색약O일때 구역의수 카운트.

queue<pair<int,int>> qu;

void bfs(int x, int y, bool isBlind) {
    if(isBlind == true && board[x][y] == 1) board[x][y] = 0;  // R과 G를 하나로 숫자 통일.

    if(visited[x][y] == 1) return;
    qu.push({x,y});
    visited[x][y] = 1;

    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] == 1) continue;

            if(isBlind == true && board[nx][ny] == 1) board[nx][ny] = 0;  // R과 G를 하나로 숫자 통일.
            if(board[cur.first][cur.second] != board[nx][ny]) continue;

            qu.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    if(isBlind == false) cnt1++;
    else cnt2++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            if(str[j] == 'G') board[i][j] = 1;
            else if(str[j] == 'B') board[i][j] = 2;
        }
    }

    // 적록색약 아닌 사람이 봤을때의 경우
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            bfs(i,j,false);
        }
    }
    fill(&visited[0][0], &visited[n-1][n-1+1], 0);

    // 적록색약인 사람이 봤을때의 경우
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            bfs(i,j,true);
        }
    }

    cout << cnt1 << " " << cnt2;


    return 0;
}