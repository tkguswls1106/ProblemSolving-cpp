#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<vector<int>> dist;

int n,m;
queue<pair<int,int>> qu;

void bfs(vector<vector<int>>& board) {  // board값을 변경하진 않을것이므로, 사실 &는 적지않아도 된다.
    
    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();
        
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || dist[nx][ny] > 0) continue;
            
            qu.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
}

int solution(vector<vector<int>> maps)
{   
    n = maps.size();
    m = maps[0].size();
    dist.resize(n, vector<int>(m));
    
    qu.push({0,0});
    dist[0][0] = 1;
    bfs(maps);
    
    if(dist[n-1][m-1] != 0) return dist[n-1][m-1];
    else return -1;
}

int main()
{
    vector<vector<int>> inputV1 = { {1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1} };
    vector<vector<int>> inputV2 = { {1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,0}, {0,0,0,0,1} };
    int answer1 = solution(inputV1);
    dist.clear();
    int answer2 = solution(inputV2);

    cout << answer1 << "\n";  // => 11 출력
    cout << answer2 << "\n";  // => -1 출력

    return 0;
}