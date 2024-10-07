#include <string>
#include <vector>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<string>> board, int h, int w) {
    
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int h2 = h + dx[i];
        int w2 = w + dy[i];
        if(h2 < 0 || h2 >= board.size() || w2 < 0 || w2 >= board[0].size()) continue;

        if(board[h][w] == board[h2][w2]) cnt++;
    }
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}