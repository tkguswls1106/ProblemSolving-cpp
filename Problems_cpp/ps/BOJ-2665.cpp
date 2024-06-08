#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n;
int board[52][52] = { 0, };
int cnt[52][52] = { 0, };  // 거리인 dist가 아닌, 검은방을 흰방으로 바꿔야할때 카운팅을 증가시킬 배열임.
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> qu;

void bfs() {
    
    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;

            int curValue = cnt[cur.first][cur.second];
            int nextValue = cnt[nx][ny];

            // 최솟값이 아닌경우 굳이 지나갈필요가 없기 때문에, cnt값이 새로 최솟값으로 갱신된 경우에만 큐에 삽입하도록 해야한다.
            if(board[nx][ny] == 0) {  // 검은방을 만났을 경우
                if(curValue + 1 < nextValue) {
                    cnt[nx][ny] = curValue + 1;
                    qu.push({nx, ny});
                }
            }
            else {
                if(curValue < nextValue) {
                    cnt[nx][ny] = curValue;
                    qu.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(&cnt[0][0], &cnt[51][52], 1e9);

    cin >> n;
    for(int i=0; i<n; i++) {
        string inputStr;
        cin >> inputStr;
        for(int j=0; j<n; j++) {
            board[i][j] = inputStr[j] - '0';
        }
    }

    qu.push({0, 0}); // cnt 배열은 어차피 0으로 선언되어있어 생략함.
    cnt[0][0] = 0;
    bfs();

    cout << cnt[n-1][n-1];


    return 0;
}