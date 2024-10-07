// - BFS 그림(2차원) 문제 (Flood Fill) -
// 참고로 이 문제는 DFS로도 풀 수 있음. 난 처음에 BFS로 풀었었음.

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>  // max함수 사용을 위해 작성하였음.

using namespace std;

// [ BFS 너비 우선 탐색 - 백준 1926 문제 ]
// - bfs함수 전체적인 과정 설명:
// 과정1. 첫좌표 먼저 큐에 push넣어주고 방문 1체크
// 과정2. while문(큐가 모두 비워지기전까지를 조건으로, 큐를 pop하며 해당 좌표의 주변인 상하좌우를 확인. 그 후 조건에 맞다면 해당 주변좌표를 큐에 push해주고 방문 1체크. 이를 반복.)
// - 시간복잡도 설명:
// 방문했던점이 아닌지 즉 시작점으로 사용가능한지 방문체크를 통하여, 총 모든 칸수만큼만 큐에 한번씩만 들어갔다 나오면 된다. 그러므로 bfs의 시간복잡도는 칸수만큼인 n*m으로 O(n*m)이 된다.

int n, m;  // n: 행(가로 => 가로줄 개수 = '세로 길이'), m: 열(세로 => 세로줄 개수 = '가로 길이')
vector<vector<int>> board;  // 그래프값 입력받은 배열
vector<vector<int>> visited;  // 방문했는지 체크할 배열 0 or 1 (헷갈릴수있겠지만 이 문제는 dist보단 visited로 코드를 짜는것이 더 적합하다.)

// 상하좌우 둘러보기위해 기존 (x,y)좌표에다가, (1,0),(0,1),(-1,0),(0,-1)씩 더해주기위한 배열임.
// 정확히는 밑의 순서는 '아랫쪽, 오른쪽, 윗쪽, 왼쪽' 이다.
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cnt = 0, maxArea = 0;  // 그림개수, 최대그림넓이
void bfs(int x, int y) {
    if (board[x][y] == 0 || visited[x][y] == 1) {  // 가지않아도되는 그래프 좌표인 board[x][y]가 0일때와, 이미 방문한적이 있는 visited[x][y]가 1일때 => BFS 적용 X
        return;  // void반환형 외부함수에서 실행중 도중 종료하고 나가기위해서는 return;을 작성해주면됨.
    }

    queue<pair<int, int>> qu;  // 방문한 좌표들을 담을 큐
    int areaSum = 0;  // 넓이 재는 변수

    qu.push({ x, y });  // 방문한 첫좌표 큐에 추가.
    visited[x][y] = 1;  // 방문했다고 체크. (큐에서 pop으로 뺄때 체크하면 안됨. push으로 넣을때 체크해야함.)
    areaSum++;  // 첫좌표에 방문성공했으니 넓이++

    while(!qu.empty()) {
        pair<int, int> cur = qu.front();  // 큐의 가장 앞 좌표를 pair객체에 먼저 할당해주고, 그 후 pop시킴. 이제 이 cur좌표 주변(상하좌우)을 둘러보면됨.
        qu.pop();

        for(int i=0; i<4; i++) {  // 주변 상하좌우칸을 살펴볼것임.
            // nx와 ny는 주변좌표 위치를 나타냄.
            int nx = cur.first + dx[i];  // cur.first는 주변의 기준이 되는 중심좌표의 x좌표값임.
            int ny = cur.second + dy[i];  // cur.second는 주변의 기준이 되는 중심좌표의 y좌표값임.

            // 이 조건문을 다른조건문보다 먼저 작성해줘야, 나중에 인덱스 접근할때 segmentation fault 에러가 안남.
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            // bfs함수 맨위 조건문과 같은 형태이자 같은 사용 이유임.
            if(board[nx][ny] == 0 || visited[nx][ny] == 1) {
                continue;  // 이는 저 위의 return;과는 달리, 함수에서 빠져나올것이 아니라 for문의 다음좌표로 확인순서를 넘겨버려 제외시키기 위함임. 또한 밑코드는 실행안되게됨.
            }

            qu.push({ nx, ny });  // 방문한 좌표 큐에 추가.
            visited[nx][ny] = 1;  // 방문했다고 체크.
            areaSum++;  // 첫좌표 이후의 좌표들에 방문성공한만큼 반복문으로 계속 넓이++
        }
    }

    cnt++;  // 그림개수 추가.
    maxArea = max(maxArea, areaSum);  // 최대그림넓이 새로고침. 이는 'maxArea = areaSum > maxArea ? areaSum : maxArea;' 로도 대체 가능한 코드줄이다.
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m));

    for(int i=0; i<n; i++) {  // 행
        for(int j=0; j<m; j++) {  // 열
            cin >> board[i][j];
        }
    }

    // 헷갈리지말자. bfs함수내에도 for문이 있음에도 함수 자체를 여러번 호출하는 이유는,
    // bfs함수 내의 for문은 상하좌우 이후의 그 상하좌우에 이어진 계속 상하좌우로 쭉 가는것이 맞지만,
    // 혹여나 중간에 가는 모든길이 끊겨서 큐가 비게될경우, 저멀리 있는 또다른 그림을 찾기위해 bfs함수 자체도 여러번 호출한 것이다.
    // 참고로 이렇게 bfs함수 자체를 여러번 호출하는 경우는 'BOJ-1926 그림'문제의 특징이지, bfs문제 대부분의 특징은 아니다.
    for(int i=0; i<n; i++) {  // 행
        for(int j=0; j<m; j++) {  // 열
            bfs(i, j);  // 그림이 끊긴상태로 여러개의 그림이 존재하므로, 멀리 떨어진 다른 그림이 있을지 모르니 BFS를 좌표(i,j)을 시작점으로 계속 바꿔주며 호출.
        }
    }

    cout << cnt << "\n";
    cout << maxArea << "\n";
    

    return 0;
}