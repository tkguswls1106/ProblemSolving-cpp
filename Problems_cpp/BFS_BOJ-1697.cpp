#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n,k;
int cnt[100002] = { 0, };  // 시간초 카운트 배열

void bfs() {
    if(cnt[n] > 0) return;

    queue<int> qu;
    qu.push(n);
    // cnt[n] = 0; 은 어차피 배열을 처음에 모두 0으로 초기화시켜줬었으므로 생략해도된다.

    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        vector<int> v = {cur-1, cur+1, cur*2};
        for(int nx : v) {
            if(nx < 0 || nx > 100000) continue;
            if(cnt[nx] > 0) continue;

            qu.push(nx);
            cnt[nx] = cnt[cur] + 1;

            if(nx == k) {  // 여기 bfs함수 내에서 이렇게 작성해도되고, 또는 모든 bfs가 끝나고 메인함수 마지막부분에서 'cout << cnt[k];'로 출력해도 된다.
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

    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }

    bfs();


    return 0;
}