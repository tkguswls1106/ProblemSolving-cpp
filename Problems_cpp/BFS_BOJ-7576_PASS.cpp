#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int m,n;
vector<vector<int>> board;
vector<vector<int>> dayV;

queue<pair<int, int>> qu;  // 이 문제의 경우, 처음에 이미 익어있는 토마토의 좌표들을 먼저 큐에 넣어주고 시작해야하므로, 큐를 전역변수로 선언한다.

void bfs() {

    while(!qu.empty()) {
        pair<int, int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];  // nx는 주변좌표의 x좌표이고, cur.first는 주변의 기준이 되는 중심좌표의 x좌표값임.
            int ny = cur.second + dy[i];  // ny는 주변좌표의 y좌표이고, cur.second는 주변의 기준이 되는 중심좌표의 y좌표값임.

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == -1) continue;  // 비어있는 토마토자리는 건너뜀.

            int newAroundDay = dayV[cur.first][cur.second] + 1;  // 주변좌표에 새롭게 주어질 day값
            if(board[nx][ny] != 1) {  // 주변좌표가 처음부터 토마토가 익어있었던 자리가 아닐때
                if(dayV[nx][ny] == -1 || newAroundDay < dayV[nx][ny]) {
                    // 아직 익었는지 주변의 해당좌표에 방문을 한번도 안했었거나 또는 새롭게 주어질 day값이 주변좌표의 기존에 할당되어있던 day값보다 작을경우, day값 교체 실시하기.
                    qu.push({nx, ny});
                    dayV[nx][ny] = newAroundDay;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;  // 열,행 순으로 입력받았으므로, 행,열 순서로 사용해야하기에 실제로 활용할때에는 순서를 반대로 넣어준다.
    board.resize(n, vector<int>(m));
    dayV.resize(n, vector<int>(m, -1));

    bool already = true;  // 처음부터 모든 토마토가 이미 익어있는 상태인지 (처음 board값이 0이 하나라도 존재하지않아야함.)
    for(int i=0; i<n; i++) {  // 행 n
        for(int j=0; j<m; j++) {  // 열 m
            cin >> board[i][j];
            if(board[i][j] == 1) {  // 처음 이미 익어있는 토마토의 좌표들을 먼저 큐에 넣어주고 시작
                qu.push({i, j});
                dayV[i][j] = 0;  // 이 문제의 경우에는 익는데걸리는 일수를 0부터 스타트해야함.
            } 

            if(board[i][j] == 0) already = false;
            if(board[i][j] == -1) dayV[i][j] = -2;  // 처음부터 토마토가 비어있는 좌표는 -2로 값을 설정해줌.
            // 즉, 결론적으로 첫좌표값의 종류는
            // 비어있음: -2, 아직방문못한좌표: 주변좌표로 닿지않아 그대로 초기값인 -1 유지(bfs 이후에도 같은값일경우 익을수없는 토마토임), 익어있음: 0(이건 bfs외부함수에서 첫부분에 초기화 해줄예정)
        }
    }
    if(already) {  // 처음부터 모든 토마토가 이미 익어있는 상태가 맞다면
        cout << 0;
        return 0;  // 출력 후 바로 메인함수모두 종료처리.
    }

    bfs();

    int maxDay = 0;  // 어차피 0이상임.
    for(auto v : dayV) {
        for(auto d : v) {
            if(d == -1) {  // bfs 종료 이후에도 익지못한 토마토(-1)가 있는경우
                cout << -1;
                return 0;
            }
            else {
                maxDay = max(maxDay, d);
            }
        }
    }

    cout << maxDay;


    return 0;
}