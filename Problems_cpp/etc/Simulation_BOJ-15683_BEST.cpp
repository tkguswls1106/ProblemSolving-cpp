// 이와 비슷하지만 보다 괜찮은 풀이는 다음 웹사이트 링크를 참고하자.
// 참고로 다음 링크 코드의 tmp배열은 arr배열을 dir반복문마다 재초기화해서 원래값으로 원상복구시켜줄 임시 배열을 의미한다.
// https://0m1n.tistory.com/115

#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> board;  // -1값이면 최종결정난 cctv가 바라본좌표임.
vector<tuple<int, int, int>> cam;  // cam 정보 <x좌표, y좌표, camType1~5>

int temp[5];  // cam1~5의 방향정보 담길 배열
int answer = 1e9;

// 차례대로 하,우,상,좌
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 한 방향인 cam1이자, BFS방식이다.
void cam1(int x, int y, vector<vector<int>>& board, int dir) {
	queue<pair<int, int>> qu;
	qu.push({ x, y });

	while (!qu.empty()) {
		pair<int, int> cur = qu.front();
		qu.pop();

		int nx = cur.first + dx[dir];
		int ny = cur.second + dy[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (board[nx][ny] == 6) continue;

		qu.push({ nx, ny });
        board[nx][ny] = -1;
    }
}

void cam2(int x, int y, vector<vector<int>>& board, int dir) {
	int dir1 = dir;
	int dir2 = (dir + 2) % 4;  // %4의 이유는, 배열이 최대인덱스를 넘어가는걸 방지하기 위해서이다.
	cam1(x, y, board, dir1);
	cam1(x, y, board, dir2);
}

void cam3(int x, int y, vector<vector<int>>& board, int dir) {
	int dir1 = dir;
	int dir2 = (dir + 1) % 4;
	cam1(x, y, board, dir1);
	cam1(x, y, board, dir2);
}

void cam4(int x, int y, vector<vector<int>>& board, int dir) {
	int dir1 = dir;
	int dir2 = (dir + 1) % 4;
	int dir3 = (dir + 2) % 4;
	cam1(x, y, board, dir1);
	cam1(x, y, board, dir2);
	cam1(x, y, board, dir3);
}

void cam5(int x, int y, vector<vector<int>>& board, int dir) {
	int dir1 = dir;
	int dir2 = (dir + 1) % 4;
	int dir3 = (dir + 2) % 4;
	int dir4 = (dir + 3) % 4;
	cam1(x, y, board, dir1);
	cam1(x, y, board, dir2);
	cam1(x, y, board, dir3);
	cam1(x, y, board, dir4);
}

void controlCam(int type, int x, int y, vector<vector<int>>& board, int dir) {
	switch (type)
	{
	case 1:
		cam1(x, y, board, dir);
		break;
	case 2:
		cam2(x, y, board, dir);
		break;
	case 3:
		cam3(x, y, board, dir);
		break;
	case 4:
		cam4(x, y, board, dir);
		break;
	case 5:
		cam5(x, y, board, dir);
		break;
	default:
		break;
	}
}

// 사각지대 카운트 함수
int getBlindspotCnt(vector<vector<int>>& board) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void dfs(int cnt) {
	if (cam.size() == cnt) {  // 모든 캠들을 dirIdx가 0~3일때에 모두 대입해보며 재귀로 전부 확인완료했을때
		vector<vector<int>> b = board;  // board를 복사해온 배열을 이용하면, 매번 자동으로 재초기화해서 사용이 가능하다.

		for (int i = 0; i < cam.size(); i++) {
			tuple<int, int, int> t = cam[i];
			int x = get<0>(t);
			int y = get<1>(t);
			int type = get<2>(t);
			controlCam(type, x, y, b, temp[i]);
		}

		answer = min(answer, getBlindspotCnt(b));
		return;
	}

	for (int dirIdx = 0; dirIdx < 4; dirIdx++) {
		temp[cnt] = dirIdx;
		dfs(cnt + 1);
        // 이는 dirIdx가 0~3일때를 모든 cam들의 좌표에 반복적으로 재귀로 확인하는것이다.
        // 예를들어 캠들의 총 개수가 2개라면, 0123 0123 이렇게 총 4번을 확인할 수 있는것이다.
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6) {
                cam.push_back({ i, j, board[i][j] });
            }
        }
    }

    dfs(0);
    cout << answer << "\n";


    return 0;
}