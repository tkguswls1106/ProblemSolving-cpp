#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[27][27] = { 0, };
int visited[27][27] = { 0, };  // 헷갈릴수있겠지만 이 문제는 dist보단 visited로 코드를 짜는것이 더 적합하다.)

queue<pair<int,int>> qu;

int cnt = 0;
vector<int> areaV;
void bfs(int x, int y) {
    if(board[x][y] == 0 || visited[x][y] == 1) return;

    qu.push({x,y});
    visited[x][y] = 1;
    int areaSum = 1;

    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == 0 || visited[nx][ny] == 1) continue;

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

    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            bfs(i,j);
        }
    }

    cout << cnt << "\n";
    sort(areaV.begin(), areaV.end());
    for(int area : areaV) {
        cout << area << "\n";
    }


    return 0;
}