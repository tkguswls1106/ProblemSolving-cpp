#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,v;

int board[1002][1002] = { 0, };
int visited[1002] = { 0, };
queue<int> qu;

// dfs를 스택말고 재귀 방법으로 풀었음.
void dfs(int x, int cnt) {  // 사실 cnt는 visited배열덕에 알아서 경로가 막히기때문에 필요없음.
    visited[x] = 1;
    cout << x << " ";

    if(cnt == n) {  // 사실 이건 visited배열덕에 경로가 막히기때문에 필요없음.
        return;
    }

    for(int i=1; i<=n; i++) {
        int canGo = board[x][i];
        int isVisited = visited[i];

        if(canGo == 0 || isVisited == 1) continue;

        dfs(i, cnt+1);  // 사실 cnt는 visited배열덕에 알아서 경로가 막히기때문에 필요없음.
    }
}

void bfs(int x) {
    qu.push(x);
    visited[x] = 1;
    cout << x << " ";

    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for(int i=1; i<=n; i++) {
            int canGo = board[cur][i];
            int isVisited = visited[i];

            if(canGo == 0 || isVisited == 1) continue;

            qu.push(i);
            visited[i] = 1;
            cout << i << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> v;
    while(m--) {
        int start,end;
        cin >> start >> end;
        
        // 양방향이므로, 두 방향 모두 삽입해줘야함.
        board[start][end] = 1;
        board[end][start] = 1;
    }

    dfs(v, 1);
    cout << "\n";
    fill(&visited[0], &visited[1002], 0);
    bfs(v);


    return 0;
}