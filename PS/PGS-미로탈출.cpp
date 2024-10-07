#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int dist[102][102] = { 0, };
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int x, int y, vector<string>& maps) {
    queue<pair<int,int>> qu;
    qu.push({x,y});
    dist[x][y] = 1;
    
    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();
        
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(maps[nx][ny] == 'X' || dist[nx][ny] > 0) continue;
            
            qu.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
}

int getDist(pair<int,int>& p) {
    int distNum = dist[p.first][p.second];
    if(distNum == 0) return -1;  // 도착하지 못했을경우 -1 반환.
    else return distNum;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    pair<int,int> s, e, l;
    n = maps.size();
    m = maps[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char ch = maps[i][j];
            if(ch == 'S') s = {i,j};
            else if(ch == 'E') e = {i,j};
            else if(ch == 'L') l = {i,j};
        }
    }
    
    // 입구부터 레버까지
    bfs(s.first, s.second, maps);
    if(getDist(l) != -1) answer += (getDist(l) - 1);
    else return -1;
    fill(&dist[0][0], &dist[n-1][m], 0);
    
    // 레버부터 출구까지
    bfs(l.first, l.second, maps);
    if(getDist(e) != -1) answer += (getDist(e) - 1);
    else return -1;
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}