#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 분리된 영역의 개수를 구해야하므로, 이는 BFS 알고리즘이 적합함.

vector<vector<int>> board;
vector<vector<int>> visited;  // 헷갈릴수있겠지만 이 문제는 dist보단 visited로 코드를 짜는것이 더 적합하다.)
queue<pair<int,int>> qu;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int m,n,k;

int cnt = 0;
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

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
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

    cin >> m >> n >> k;  // 문제상 세로,가로를 m,n 순서로 넣어주므로, 나중에 이를 활용할때에도 평소처럼 n,m이 아닌 반대 순서로 m,n으로 넣어주면 된다.
    board.resize(m, vector<int>(n));
    visited.resize(m, vector<int>(n));

    for(int i=0; i<k; i++) {  // while(k--) { } 로도 사용가능하다.
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int q = y1; q < y2; q++) {  // 모눈종이 좌표는x다음y가 아닌 y다음x로 순서를 바꿔서 이중for문에 넣기. 참고로 부등호는 <로 작성하면 됨.
            for(int w = x1; w < x2; w++) {
                board[q][w] = 1;
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
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