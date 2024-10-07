#include <vector>
#include <iostream>

using namespace std;

int n;
int cnt = 0;

vector<pair<int,int>> v;  // 놔둔 퀸 좌표의 목록들 배열
int visited[17][17] = { 0, };

// < 퀀 두기 가능 확인법 >
// - 같은 가로인지 확인: 같은행에 다른 퀸이 있으면 안되므로, 이건 퀸을 설치하면 x+1로 바로 다음행으로 넘어가게하는것으로 해결 가능하다.
// - 같은 세로인지 확인: y1 == y2 로 y값이 같은지
// - 같은 대각선인지 확인: abs(x1 - x2) == abs(y1 - y2) 인지
void func(int x) {  // x는 row행을 의미한다. 그리고 동시에 현재 담겨있는 퀸좌표들의 개수를 의미한다.
    if(x == n) {
        cnt++;
        return;
    }

    for(int y=0; y<n; y++) {  // 열 변경.
        if(visited[x][y] == 1) continue;
        bool isAble = true;  // 퀸을 놔두어도되는가?
        for(auto queenCur : v) {
            if(y == queenCur.second || abs(x - queenCur.first) == abs(y - queenCur.second)) {  // 같은 세로인지 확인 || 같은 대각선인지 확인
                isAble = false;
                break;
            }
        }
        if(isAble == false) continue;

        v.push_back({x,y});  // push_back을 해줌으로써 퀸의개수인 0개였던 x개가 x+1개인 1개가 됨.
        visited[x][y] = 1;
        func(x+1);  // push_back으로 인해 x+1이 되었으므로 이를 반영하여 다시 재귀로 호출함. 참고로 이는 같은 가로에 퀸이1개이도록 행 변경의 의미도 함.
        // 만약 x+1이 n과 같아진다면 이외 코드실행없이 바로 출력이되고 return;이 실행되며 최근 재귀가 종료된다.
        // 위를 만약에 x가 아닌 v.size()로 확인하여 재귀가 아니게된다면, 다시 이전으로 되돌아가 확인하는 백트래킹이 성립이 안되므로 안된다.

        v.pop_back();
        visited[x][y] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    func(0);
    cout << cnt;


    return 0;
}