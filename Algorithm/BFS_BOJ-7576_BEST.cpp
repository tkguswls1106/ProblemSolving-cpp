// - BFS 2차원 토마토 문제 -

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// - 풀이순서 팁 설명:
// 처음에 이미 익어있는 토마토를 큐에 넣어준상태로 시작하며, 처음에 안익어있던 토마토는 유별나게 티날수있게 따로 day를 -1로 설정해두고 시작하기.

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int m,n;  // m: 열(세로 => 세로줄 개수 = '가로 길이'), n: 행(가로 => 가로줄 개수 = '세로 길이')
vector<vector<int>> board;
vector<vector<int>> dayV;

queue<pair<int, int>> qu;  // 이 문제의 경우, 처음에 이미 익어있는 토마토의 좌표들을 먼저 큐에 넣어주고 시작해야하므로, 큐를 전역변수로 선언한다.

void bfs() {
    // 이미 시작 익은토마토들을 메인함수에서 bfs호출전에 큐에 모두 넣어두었고 for문 없이 이를 활용하기때문에, 초반에 bfs함수의 파라미터로 x,y좌표변수를 받아 if조건문으로 걸러주는 코드줄은 필요가 없다.

    while(!qu.empty()) {
        pair<int, int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];  // nx는 주변좌표의 x좌표이고, cur.first는 주변의 기준이 되는 중심좌표의 x좌표값임.
            int ny = cur.second + dy[i];  // ny는 주변좌표의 y좌표이고, cur.second는 주변의 기준이 되는 중심좌표의 y좌표값임.

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dayV[nx][ny] != -1) continue;  // 안익은토마토가 아니라면 건너뜀. 비어있거나 익은토마토인 경우는 건너뛴다는 뜻임. (즉, 안익은토마토만 bfs 적용시키겠다는 뜻임.)

            qu.push({nx,ny});
            dayV[nx][ny] = dayV[cur.first][cur.second] + 1;  // 주변좌표의 day값 = 기준좌표 day값 + 1; (참고로 어차피 기존에 day가 -1이었어도, 0에서 +1값을 덮어씌우기에 문제없음.)
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;  // 열,행 순으로 입력받았으므로, 행,열 순서로 사용해야하기에 실제로 활용할때에는 순서를 반대로 넣어준다.
    board.resize(n, vector<int>(m));
    dayV.resize(n, vector<int>(m));

    for(int i=0; i<n; i++) {  // 행 n
        for(int j=0; j<m; j++) {  // 열 m
            cin >> board[i][j];
            if(board[i][j] == 1) {  // 처음 이미 익어있는 토마토의 좌표들을 먼저 큐에 넣어주고 시작
                qu.push({i, j});
                // 익은 토마토 시작 day는 0부터이어야 한다. 어차피 이미 시작 day는 벡터가 0으로 초기화되어있어서, 추가적으로 dayV[i][j] = 0; 코드를 적지 않아도 된다.
            }
            else if(board[i][j] == 0) {  // 처음 안익은 토마토는 day를 -1로 둠.
                dayV[i][j] = -1;
            }
            // 이렇게되면, 비어있거나 익은토마토는 모두 day가 0이 되고, 안익은토마토는 -1으로 지정됨.
        }
    }

    bfs();

    int maxDay = 0;  // 어차피 0이상임.
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(dayV[i][j] == -1) {  // bfs 종료 이후에도 안익은토마토(-1)가 아직남아 있는경우
                cout << -1;
                return 0;  // 토마토가 모두 익지는 못하는 상황에는 -1을 출력하고 종료.
            }
            else {
                maxDay = max(maxDay, dayV[i][j]);
            }
        }
    }
    cout << maxDay;


    return 0;
}