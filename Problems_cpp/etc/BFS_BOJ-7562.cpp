#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int t;
int n;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

int dist[302][302] = { 0, };

queue<pair<int,int>> qu;

void bfs() {

    while(!qu.empty()) {
        pair<int,int> cur = qu.front();
        qu.pop();

        for(int i=0; i<8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny] > 0) continue;

            qu.push({nx,ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;

            // 이동할자리가 그대로인 dist가 0인 경우도 있을수있기때문에 사용해서는 안되는 코드이다.
            // if(nx == c && ny == d) {
            //     cout << dist[nx][ny] << "\n";
            //     return;
            // }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        int a,b,c,d;

        cin >> a >> b >> c >> d;
        qu.push({a,b});

        if(a==c && b==d) {
            // 이동할 자리가 제자리일경우, 그대로 0을 출력해준다. 
            // 굳이 if문으로 나눠준 이유는, dist가 그대로0인 자리라 조건문에 continue로 걸리지않아 같은 자리에 다시 돌아오게되면 dist값이 늘어나기 때문이다.
            cout << 0 << "\n";
        }
        else {
            bfs();
            cout << dist[c][d] << "\n";
            fill(&dist[0][0], &dist[n-1][n-1+1], 0);
        }
    }


    return 0;
}