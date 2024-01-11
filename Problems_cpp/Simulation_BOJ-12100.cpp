#include <vector>
#include <iostream>
#include <deque>  // 덱deque은 마치 vector의 기능에 push_front(넣을값)와 pop_front()를 추가한 자료구조임.
#include <algorithm>

using namespace std;

// - 문제풀이 팁:
// 기울이는 방향은 왼쪽 하나로 고정해두고, 기울이기전에 배열을 먼저 회전시켜서 기울기 방향을 바꾸는듯한 방식으로 생각하면 편하다.
// - 90도 회전 인덱스 팁:
// A			 B
// 00 01 02		 00(20) 01(10) 02(00)	// 00 => 20, 21 => 12 등등
// 10 11 12  =>  10(21) 11(11) 12(01)	// B[x][y] = A[?][x] 이며, ?값은 결국 n-1-y 이 됨.
// 20 21 22		 20(22) 21(12) 22(02)

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

void left(vector<vector<int>>& boardTmp) {  // 왼쪽 방향에서 기울이기

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
				dq.pop_back();
				dq.push_back(boardTmp[i][j] * 2);
				isAdd = true;
			}
			else {
				dq.push_back(boardTmp[i][j]);
				isAdd = false;
			}
		}
 
		int dqSize = dq.size();
		for(int k=0; k<n; k++) {  // 열을 왼쪽부터 오른쪽방향으로 차례로 투입.
			if(k < dqSize) {
				boardTmp[i][k] = dq.front();  // 덱의 안쪽값부터 차례로 투입.
				dq.pop_front();
			}
			else {
				boardTmp[i][k] = 0;
			}
		}
	}
}

void rotateNleft(vector<vector<int>>& boardTmp, int rotateCnt) {  // 90도 회전을 1~4 원하는횟수만큼 진행 후에, 기울기 실시.
	while(rotateCnt--) {
		rotate(boardTmp);
	}
	left(boardTmp);
}

int getMax(vector<vector<int>>& boardTmp) {
	int maxValue = -1;
	for(int i=0; i<boardTmp.size(); i++) {
		maxValue = max(maxValue, *max_element(boardTmp[i].begin(), boardTmp[i].end()));
	}
	
	return maxValue;
}

vector<vector<vector<int>>> boardBT;  // board배열을 백트래킹했을때 2차원배열 종류들 담을 3차원배열 (참고로 맨처음엔 board 원본배열이 들어감.)
vector<int> resultV;  // 백트래킹 결과 5번 채웠을경우들의 maxResult값을 넣어줄 배열
void bt(int k) {  // 백트래킹 함수 (이전 배열로 되돌아가며 모든 경우의 수 확인함.)
	if(k == 5) {  // 최대인 5번을 모두 이동시켰다면
		resultV.push_back(getMax(boardBT.back()));
		return;
	}

	for(int i=1; i<=4; i++) {  // i는 90도 회전횟수를 의미함. (그러므로 회전횟수4와 최대이동수5를 고려하면, 가능한 가짓수는 총 4^5 이다.)
		vector<vector<int>> boardTmp = boardBT.back();  // 복사해서 새로운 배열로 만들어주지않으면, 원본인 boardBT.back()가 바뀌게 되므로 주의해야한다!
		rotateNleft(boardTmp, i);
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
		}
	}

	boardBT.push_back(board);
	bt(0);

	cout << *max_element(resultV.begin(), resultV.end());


	return 0;
}