// - DFS 그림(2차원) 문제 (Flood Fill) -
// 참고로 이 문제는 BFS로도 풀 수 있음. 난 처음에 BFS로 풀었었음.

#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

// [ DFS 깊이 우선 탐색 - 백준 1926 문제 ]

int n,m;
int board[502][502] = { 0, };
int visited[502][502] = { 0, };
stack<pair<int,int>> st;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int cnt = 0, maxArea = 0;

void dfs(int x, int y) {
    if(board[x][y] == 0 || visited[x][y] == 1) return;

    st.push({x,y});
    visited[x][y] = 1;
    int areaSum = 1;

    while(!st.empty()) {
        pair<int,int> cur = st.top();
        st.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || visited[nx][ny] == 1) continue;

            st.push({nx,ny});
            visited[nx][ny] = 1;
            areaSum++;
        }
    }
    
    maxArea = max(maxArea, areaSum);
    cnt++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dfs(i,j);
        }
    }

    cout << cnt << "\n" << maxArea;


    return 0;
}