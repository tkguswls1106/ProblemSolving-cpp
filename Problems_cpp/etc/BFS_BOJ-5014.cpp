#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int f,s,g,u,d;
vector<int> v;
int dist[1000002] = { 0, };
queue<int> qu;

void bfs() {

    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for(int n : v) {
            int nx = cur + n;

            if(nx < 1 || nx > f) continue;
            if(dist[nx] > 0) continue;

            qu.push(nx);
            dist[nx] = dist[cur] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> f >> s >> g >> u >> d;
    v = {u, -d};
    
    qu.push(s);
    dist[s] = 1;
    bfs();

    if(dist[g] == 0) cout << "use the stairs";
    else cout << dist[g]-1;


    return 0;
}