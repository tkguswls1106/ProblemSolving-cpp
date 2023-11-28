// - BFS 3차원 토마토 문제 -

#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

// - 풀이순서 팁:
// 처음에 이미 익어있는 토마토를 큐에 넣어준상태로 시작하며, 처음에 안익어있던 토마토는 유별나게 티날수있게 따로 day를 -1로 설정해두고 시작하기.
// - 실수했던 점:
// 3차원 좌표순회 for반복문에서의 인덱스 x,y,z 좌표 순서를 주의해야한다.

int m,n,h;  // y x z 순으로 받은거임.
int board[102][102][102] = { 0, };  // [x][y][z] 순으로 좌표를 넣어두었음.
int day[102][102][102] = { 0, };  // [x][y][z] 순으로 좌표를 넣어두었음.

// 상,하,좌,우,위,아래 => 6칸
int dx[6] = { 1,0,-1,0,0,0 };  // 기존 dx[4]인 1,0,-1,0 에다가 0,0 추가
int dy[6] = { 0,1,0,-1,0,0 };  // 기존 dy[4]인 0,1,0,-1 에다가 0,0 추가
int dz[6] = { 0,0,0,0,1,-1 };  // z축이고 위아래만 주변좌표를 만들어주면 되므로, {x,y,z}가 {0,0,1},{0,0,-1}이 되도록 끝에 1,-1 추가

queue<tuple<int,int,int>> qu;  // 이 문제의 경우, 처음에 이미 익어있는 토마토의 좌표들을 먼저 큐에 넣어주고 시작해야하므로, 큐를 전역변수로 선언한다.

void bfs() {
    // 이미 시작 익은토마토들을 메인함수에서 bfs호출전에 큐에 모두 넣어두었고 for문 없이 이를 활용하기때문에, 초반에 bfs함수의 파라미터로 x,y,z좌표변수를 받아 if조건문으로 걸러주는 코드줄은 필요가 없다.

    while(!qu.empty()) {
        tuple<int,int,int> cur = qu.front();  // cur은 주변좌표의 기준이되는 중심좌표
        qu.pop();

        for(int i=0; i<6; i++) {  // 이 for문은 3차원 좌표순회를 하는것이 아니기에, 좌표를 x y z 순으로 그대로 넣어주면 된다.
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<2>(cur) + dz[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m || nz<0 || nz>=h) continue;
            if(day[nx][ny][nz] != -1) continue;  // 안익은토마토가 아니라면 bfs 적용 안시킴.

            qu.push({nx,ny,nz});
            day[nx][ny][nz] = day[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 3차원 좌표순회 for반복문에서의 인덱스 x,y,z 좌표 순서를 주의해야한다!!

    cin >> m >> n >> h;  // y x z 순으로 받은거임.
    for(int i=0; i<h; i++) {  // 높이 z
        for(int j=0; j<n; j++) {  // 세로(행) x
            for(int k=0; k<m; k++) {  // 가로(열) y
                cin >> board[j][k][i];
                int b = board[j][k][i];

                if(b == 1) {  // 처음부터 익은토마토
                    qu.push({j,k,i});  // x y z 순으로 좌표를 넣어야하므로, j j k 가 아닌 j k i 순으로 넣어야한다. for반복문에서 push할때 좌표순서를 주의하자.
                    // day는 이미0이라서 생략.
                }
                else if(b == 0) {  // 처음부터 안익은토마토
                    day[j][k][i] = -1;
                }
            }
        }
    }

    bfs();

    int maxDay = 0;  // 어차피 0이상임.
    for(int i=0; i<h; i++) {  // 높이 z
        for(int j=0; j<n; j++) {  // 세로(행) x
            for(int k=0; k<m; k++) {  // 가로(열) y
                int d = day[j][k][i];

                if(d == -1) {
                    cout << -1;
                    return 0;
                }
                else {
                    maxDay = max(maxDay, d);
                }
            }
        }
    }
    cout << maxDay;


    return 0;
}