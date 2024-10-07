#include <vector>
#include <stack>

using namespace std;

// - 문제 지문 이해:
// 주어진 board 배열은 가로(행) 순이 아닌, 세로(열) 순으로 주어진 것이다.

stack<int> st;
int cnt = 0;

void func(vector<vector<int>>& board, int idx) {  // 배열의 세로(열) 순회 함수
    for(int i=0; i<board.size(); i++) {  // row행만 변경
        if(board[i][idx] != 0) {
            int top = st.top();
            if(top == board[i][idx]) {
                st.pop();
                cnt+=2;
            }
            else {
                st.push(board[i][idx]);
            }
            
            board[i][idx] = 0;
            break;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    
    st.push(0);
    
    for(int n : moves) {
        int idx = n-1;
        func(board, idx);
    }    
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}