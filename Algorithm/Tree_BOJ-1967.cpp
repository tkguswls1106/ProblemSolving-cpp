// - 트리 문제 -
// 이 문제는 DFS로 풀었음.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// - 문제풀이 과정:
// 1. 특정 정점에서부터 한번 dfs를 돌아서 가장 멀리 있는 리프노드지점을 찾는다.
// 2. 찾은 해당 지점에서부터 다시 dfs를 돌아서 가장 멀리 있는 지점과의 거리를 구하면 된다.

vector<pair<int,int>> adj[10002];
int visited[10002] = { 0, };

int maxEndPoint = 0, maxDistSum = 0;
void dfs(int start, int distSum) {
    if(maxDistSum < distSum) {
        maxEndPoint = start;
        maxDistSum = distSum;
    }

    for(auto nextAdj : adj[start]) {
        int next = nextAdj.first;
        int dist = nextAdj.second;

        if(visited[next] == 1) continue;

        visited[next] = 1;
        dfs(next, distSum + dist);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a,b,dist;
        cin >> a >> b >> dist;
        
        adj[a].push_back({b, dist});
        adj[b].push_back({a, dist});
    }

    visited[1] = 1;
    dfs(1, 0);
    fill(&visited[0], &visited[10002], 0);
    maxDistSum = 0;
    
    visited[maxEndPoint] = 1;
    dfs(maxEndPoint, 0);
    
    cout << maxDistSum;


    return 0;
}