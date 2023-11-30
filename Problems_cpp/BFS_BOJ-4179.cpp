// - BFS 미로+불 문제 -

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int r,c;
int board[1002][1002] = { 0, };  // 1은 이동가능한칸, 0은 이동불가능한칸
int distF[1002][1002] = { 0, };  // 불 이동거리(이동시간)
int distJ[1002][1002] = { 0, };  // 지훈 이동거리(이동시간)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int, int>> fqu;
queue<pair<int, int>> jqu;

bool bfsEnd = false;

// 시작 불의좌표 F가 여러개일수 있다는점의 주의해서 풀어야한다! (즉, 메인함수에서 먼저 전역변수인 큐에 push를 하고 시작한다.)

void bfs() {
    
    while(!fqu.empty()) {  // 먼저 불 이동거리부터 계산
        pair<int, int> cur = fqu.front();
        fqu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == 0 || board[nx][ny] == -1 || distF[nx][ny] > 0) continue;

            fqu.push({nx, ny});
            distF[nx][ny] = distF[cur.first][cur.second] + 1;
        }
    }

    while(!jqu.empty()) {  // 그다음으로 지훈 이동거리를 계산
        pair<int, int> cur = jqu.front();
        jqu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {  // 이는 가장자리에 도달했다는 의미므로
                cout << distJ[cur.first][cur.second];  // 거리 시작을 1로 스타트했으므로, 가장자리 이동전 기존좌표의 거리로 출력을 하면된다.
                bfsEnd = true;  // bfs를 성공적으로 종료했음을 의미함.
                return;
            }
            if(board[nx][ny] == 0 || board[nx][ny] == -1 || distJ[nx][ny] > 0) continue;

            if(distF[nx][ny] > 0 && distJ[cur.first][cur.second] + 1 >= distF[nx][ny])
                continue;  // 만약 이미 불이 지나갔던 자리인데 && 지훈의 이동거리(이동시간)가 불의 이동거리(이동시간)보다 같거나 크게되면 안됨.

            jqu.push({nx, ny});
            distJ[nx][ny] = distJ[cur.first][cur.second] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++) {
        string str;
        cin >> str;
        for(int j=0; j<c; j++) {
            if(str[j] == '#') board[i][j] = -1;
            else if(str[j] == '.') board[i][j] = 1;
            else if(str[j] == 'J') {
                board[i][j] = 1;
                jqu.push({i,j});
                distJ[i][j] = 1;
            }
            else if(str[j] == 'F') {
                board[i][j] = 0;
                fqu.push({i,j});
                distF[i][j] = 1;
            }
        }
    }
    
    bfs();
    if(bfsEnd == false) cout << "IMPOSSIBLE";


    return 0;
}