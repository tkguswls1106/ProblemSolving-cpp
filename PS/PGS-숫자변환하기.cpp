#include <queue>

using namespace std;

int cnt[3000002] = { 0, };

void bfs(int x, int y, int n) {
    queue<int> qu;
    qu.push(x);
    cnt[x] = 1;
    
    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        
        for(int nx : {cur+n, cur*2, cur*3}) {
            if(nx<0 || nx>=3000002) continue;
            if(cnt[nx] > 0) continue;
            
            qu.push(nx);
            cnt[nx] = cnt[cur] + 1;
            
            if(nx == y) return;
        }
    }
}

int solution(int x, int y, int n) {
    bfs(x, y, n);
    return cnt[y] != 0 ? cnt[y]-1 : -1;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}