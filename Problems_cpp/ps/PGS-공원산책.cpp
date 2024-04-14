#include <string>
#include <vector>

using namespace std;

pair<int,int> move(char ch) {
    pair<int,int> p;
    if(ch == 'N') p = {-1, 0};
    else if(ch == 'S') p = {1, 0};
    else if(ch == 'W') p = {0, -1};
    else p = {0, 1};  // ch == 'E' 일때
    
    return p;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    
    pair<int,int> startP;
    int board[52][52] = { 0, };
    for(int i=0; i<park.size(); i++) {
        for(int j=0; j<park[0].size(); j++) {
            if(park[i][j] == 'S') {
                board[i][j] = 1;
                startP = {i,j};
                continue;
            }
            else if(park[i][j] == 'O') {
                board[i][j] = 1;
            }
        }
    }
    
    pair<int,int> p;
    int x ,y;
    for(string str : routes) {
        p = move(str[0]);
        
        int x = startP.first, y = startP.second;
        int moveCnt = str[2] - '0';
        bool isAble = true;
        while(moveCnt--) {
            x += p.first;
            y += p.second;
            
            if(x < 0 || x >= park.size() || y < 0 || y >= park[0].size()
               || board[x][y] == 0) {
                isAble = false;
                break;
            }
        }
        
        if(isAble == true) {
            startP.first = x;
            startP.second = y;
        }        
    }
    
    return {startP.first, startP.second};
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}