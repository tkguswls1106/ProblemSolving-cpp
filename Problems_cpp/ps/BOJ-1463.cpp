#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// DP 문제이지만, 나는 BFS로 풀었음.

int n;
int cnt[1000002] = { 0, };
queue<int> qu;

void bfs() {

	while(!qu.empty()) {
		int cur = qu.front();
		qu.pop();

		vector<int> v = { cur-1 };
		if(cur%3 == 0) v.push_back(cur/3);
		if(cur%2 == 0) v.push_back(cur/2);
		for(int nx : v) {
			if(nx < 1) continue;
			if(cnt[nx] > 0) continue;

			qu.push(nx);
			cnt[nx] = cnt[cur] + 1;

			if(nx == 1) {
				cout << cnt[nx];
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	if(n == 1) {
		cout << 0;
		return 0;
	}

	qu.push(n);
	bfs();


	return 0;
}