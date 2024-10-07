// < 시간초과 FAIL 코드 >
// 예시에 대한 답은 맞게 나옴. 하지만 채점을 하면 시간초과로 실패함.
// 백준 12094번인 이 2048(hard) 문제는, 2048(easy) 문제인 Simulation_BOJ-12100.cpp 문제 코드와 비교하자면,
// 거기에 2가지 시간단축의 조건을 추가하고, 불필요한 함수들을 제거 및 통합시켜 최대한 최적화 시켜 코드를 수정했음에도 불구하고, 결국 시간초과가 뜸.

#include <vector>
#include <iostream>
#include <deque>  // 덱deque은 마치 vector의 기능에 push_front(넣을값)와 pop_front()를 추가한 자료구조임.
#include <algorithm>
#include <cmath>

using namespace std;

// - 문제풀이 팁:
// 기울이는 방향은 왼쪽 하나로 고정해두고, 기울이기전에 배열을 먼저 회전시켜서 기울기 방향을 바꾸는듯한 방식으로 생각하면 편하다.
// - 90도 회전 인덱스 팁:
// A			 B
// 00 01 02		 00(20) 01(10) 02(00)	// 00 => 20, 21 => 12 등등
// 10 11 12  =>  10(21) 11(11) 12(01)	// B[x][y] = A[?][x] 이며, ?값은 결국 n-1-y 이 됨.
// 20 21 22		 20(22) 21(12) 22(02)
// - 시간단축 팁:
// 1. 모든 이동에 배열에 변화가 있어야지 최댓값을 구하기 용이하기에, 이동후에 배열에 변화가 없다면, 해당 경우는 중단시키고 넘어가게한다.
// => 이동(밀기)후에, 배열 변화가 없이 그대로같다면 중단 실시.
// 2. 만약 현재 배열의 값으로 남은 이동횟수만큼 움직였을때 나올수있는 최댓값이, 지금 이미 백트래킹으로 연산되어 결과로 나왔었던 최댓값보다 같거나작다면, 해당 경우는 중단시키고 넘어가게한다.
// => rotateNleft함수로 이동후에, '이동후최댓값 x 2^남은이동횟수'가 이미 maxResult보다 같거나작다면 중단 실시.

int n;
vector<vector<int>> board;

// 밑의 rotate함수를 백트래킹으로 계속 이전으로 되돌아가보며, 모든 경우의 수를 탐색해보아야한다.
void rotate(vector<vector<int>>& boardTmp) {  // 기울이기전에 먼저 회전부터 시키기 (이는 90도 한번만 회전하는 함수이며, 가능한 경우는 총 시계방향 회전횟수 1~4)

	vector<vector<int>> temp(n, vector<int>(n));  // vector<vector<int>> temp = boardTmp; 로 작성하여도 딱히 상관없다.
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			temp[i][j] = boardTmp[n-1-j][i];
		}
	}
	boardTmp = temp;
}

int maxLeft = -1;
bool left(vector<vector<int>>& boardTmp) {  // 왼쪽 방향에서 기울이기. & 그리고 배열이 변화했는지 체크해서 반환해줌. & 이동후 해당 경우 안에서의 최댓값도 계산해줌.

    bool isChange = false;  // 배열이 변화했는가?
    for(int i=0; i<n; i++) {  // 행
		deque<int> dq;
		bool isAdd = false;  // 합쳤는가?
		for(int j=0; j<n; j++) {  // 열을 왼쪽부터 오른쪽방향으로 차례로 투입.
			if(boardTmp[i][j] == 0) continue;
			if(dq.empty()) {
				dq.push_back(boardTmp[i][j]);
				continue;
			}
			
			if(dq.back() == boardTmp[i][j] && isAdd == false) {  // ~ && 아직 이전에 합하지않았을때
                int merge = boardTmp[i][j] * 2;
                dq.pop_back();
				dq.push_back(merge);

                maxLeft = max(maxLeft, merge);  // 합쳤으니 maxLeft값과 비교확인후 갱신.
				isAdd = true;
                isChange = true;
			}
			else {
				dq.push_back(boardTmp[i][j]);
				isAdd = false;
			}
		}
 
		int dqSize = dq.size();
		for(int k=0; k<n; k++) {  // 열을 왼쪽부터 오른쪽방향으로 차례로 투입.
			if(k < dqSize) {
                if(boardTmp[i][k] != dq.front()) isChange = true;
				boardTmp[i][k] = dq.front();  // 덱의 안쪽값부터 차례로 투입.
				dq.pop_front();
			}
			else {  // 그럼 이제 덱을 넘어서는 인덱스범위이므로, boardTmp에는 빈공간값인 0을 넣어주면 됨.
                if(boardTmp[i][k] != 0) isChange = true;
				boardTmp[i][k] = 0;
			}
		}
	}

    return isChange;
}

bool rotateNleft(vector<vector<int>>& boardTmp, int rotateCnt) {  // 90도 회전을 1~4 원하는횟수만큼 진행 후에, 기울기 실시. (이동)
	while(rotateCnt--) {
		rotate(boardTmp);
	}
	bool isChange = left(boardTmp);

    return isChange;
}

vector<vector<vector<int>>> boardBT;  // board배열을 백트래킹했을때 2차원배열 종류들 담을 3차원배열 (참고로 맨처음엔 board 원본배열이 들어감.)
int maxResult = -1;  // 백트래킹 결과 10번 채웠을경우들의 maxResult값을 갱신할 변수임.
void bt(int k) {  // 백트래킹 함수 (이전 배열로 되돌아가며 모든 경우의 수 확인함.)
	if(k == 10) {  // 최대인 10번을 모두 이동시켰다면
        maxResult = max(maxResult, maxLeft);
        return;
	}

	for(int i=1; i<=4; i++) {  // i는 90도 회전횟수를 의미함. (그러므로 회전횟수4와 최대이동수10을 고려하면, 가능한 가짓수는 총 4^10 이다.)
		vector<vector<int>> boardTmp = boardBT.back();  // 복사해서 새로운 배열로 만들어주지않으면, 원본인 boardBT.back()가 바뀌게 되므로 주의해야한다!
		bool isChange = rotateNleft(boardTmp, i);  // 이동

        if(isChange == false) {  // 시간단축을 위해, 이동후 배열에 변화가 없다면 중단시키고 넘어가게함.
            continue;
        }
        if((maxLeft * pow(2, 10-(k+1))) <= maxResult) {  // 시간단축을 위해, '이동후최댓값 x 2^남은이동횟수'가 이미 maxResult보다 같거나작다면 중단시키고 넘어가게함.
            continue;
        }
    
		boardBT.push_back(boardTmp);
		bt(k+1);

		boardBT.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	board.resize(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> board[i][j];
            maxLeft = max(maxLeft, board[i][j]);
        }
	}

	boardBT.push_back(board);
	bt(0);

	cout << maxResult;


	return 0;
}