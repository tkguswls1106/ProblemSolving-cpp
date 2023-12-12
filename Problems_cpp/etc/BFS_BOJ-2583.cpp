#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 분리된 영역의 개수를 구해야하므로, 이는 BFS 알고리즘이 적합함.
// board가 0인 부분만 BFS로 돌며 방문하면 된다.
// 오른쪽 위 꼭짓점의 좌표가 구해질때, 이 좌표의 x,y좌표를 모두 -1시켜서 모눈종이말고 그래프 형식에 가깝게 좌표를 보정하도록 하자.
// 위의 예시설명: 모눈종이의 왼쪽아래꼭짓점좌표 오른쪽위꼭짓점좌표 (0,2) (4,4) -> 그래프상의 왼쪽아래꼭짓점좌표 오른쪽위꼭짓점좌표 위치좌표 (0,2) (3,3) {물론, x,y좌표는 그래프에서 교체해야함.}

vector<vector<int>> board;
vector<vector<int>> visited;
queue<pair<int,int>> qu;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int m,n,k;

int cnt;
vector<int> areaV;
void bfs(int x, int y) {
    if(board[x][y] == 1 || visited[x][y] == 1) return;

    qu.push({x,y});
    visited[x][y] = 1;
    int areaSum = 1;

    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 1 || visited[nx][ny] == 1) continue;

            qu.push({nx,ny});
            visited[nx][ny] = 1;
            areaSum++;
        }
    }

    cnt++;
    areaV.push_back(areaSum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;  // 문제상 세로,가로를 m,n 순서로 넣어주므로, 코드로는 반대 순서로 넣어주면 된다.
    board.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m));

    for(int i=0; i<k; i++) {
        int a,b,c,d;
        cin >> b >> a >> d >> c;  // a,b,c,d 순서를 x좌표와 y좌표 순서를 바꿔서 입력하자. 그 이유는 모눈종이의 좌표계산 방식과 그래프는 다르기 때문이다.
        c--; d--;  // 모눈종이의 오른쪽위꼭짓점좌표를 -1시켜서 모눈종이말고 그래프 형식에 가깝게 좌표를 보정
        if(a >= n) a = n-1;
        if(b >= m) b = m-1;

        for(int q=a; q<=c; q++) {
            for(int w=b; w<=d; w++) {
                board[q][w] = 1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            bfs(i,j);
        }
    }
    sort(areaV.begin(), areaV.end());

    cout << cnt << "\n";
    for(int area : areaV) {
        cout << area << " ";
    }


   return 0;     
}