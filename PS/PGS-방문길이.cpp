#include <string>
#include <vector>

using namespace std;

int visited[12][12][4] = { 0, };  // 0: 상, 1: 하, 2: 좌, 3:우

pair<int,int> move(char ch) {
    if(ch == 'U') return {0,1};
    else if(ch == 'D') return {0,-1};
    else if(ch == 'R') return {1,0};
    else return {-1,0};  // ch == 'L'
}

int solution(string dirs) {
    int x=5, y=5, cnt=0;  // 시작점은 (0+5,0+5)로 설정
    
    for(int i=0; i<dirs.size(); i++) {
        char ch = dirs[i];
        auto p = move(ch);
        int nx = x + p.first;
        int ny = y + p.second;
        if (nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;
        
        if(ch == 'U') {
            if(!visited[x][y][0] && !visited[nx][ny][1]) cnt++;
            visited[x][y][0] = 1;   // (x,y)에서 위로 이동
            visited[nx][ny][1] = 1;  // (nx,ny)에서 아래로 이동
        }
        else if(ch == 'D') {
            if(!visited[x][y][1] && !visited[nx][ny][0]) cnt++;
            visited[x][y][1] = 1;
            visited[nx][ny][0] = 1;
        }
        else if(ch == 'R') {
            if(!visited[x][y][3] && !visited[nx][ny][2]) cnt++;
            visited[x][y][3] = 1;
            visited[nx][ny][2] = 1;
        }
        else {  // ch == 'L'
            if(!visited[x][y][2] && !visited[nx][ny][3]) cnt++;
            visited[x][y][2] = 1;
            visited[nx][ny][3] = 1;
        }
        
        x = nx;
        y = ny;
    }
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}