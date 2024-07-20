#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4];
int dy[4];
vector<vector<int>> board;
int visited[102][102];
int row, col;  // row 인덱스, column 인덱스
int color, areaCnt, areaSum, maxAreaSum;

void bfs(int x, int y) {
    if(board[x][y] == 0 || visited[x][y] == 1) return;
    color = board[x][y];
    
    queue<pair<int,int>> qu;
    qu.push({x,y});
    visited[x][y] = 1;
    areaSum++;
    
    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();
        
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx<0 || nx>=row || ny<0 || ny>=col) continue;
            if(board[nx][ny] == 0 || visited[nx][ny] == 1) continue;
            if(color != board[nx][ny]) continue;

            qu.push({nx,ny});
            visited[nx][ny] = 1;
            areaSum++;
        }
    }
    
    areaCnt++;
    maxAreaSum = max(maxAreaSum, areaSum);
    areaSum = 0;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // 이 문제는 이상하게도, 전역변수를 반드시 solution 안에서만 초기화해주어야 정답 처리된다.
    dx[0]=1, dx[1]=0, dx[2]=-1, dx[3]=0;  // dx[4] = { 1, 0, -1, 0 };
    dy[0]=0, dy[1]=1, dy[2]=0, dy[3]=-1;  // dy[4] = { 0, 1, 0, -1 };
    board = picture;
    fill(&visited[0][0], &visited[101][102], 0);
    row = m, col = n;
    color = 0, areaCnt = 0, areaSum = 0, maxAreaSum = 0;
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            bfs(i, j);
        }
    }
    
    return {areaCnt, maxAreaSum};
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}