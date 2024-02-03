// - 트리 문제 (BFS 방식) -

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// - 트리의 정의 및 성질:
// 트리란 자료구조의 일종이며, '사이클이 없이' '모든 정점이 연결'되어있는 무방향의 '그래프'이다. (중요 1)
// 모든 정점이 연결되어있지만 사이클이 없기에, 정점의 개수가 V개이면 간선의 개수는 V-1개이다. (중요 2)
// 사이클이 존재하지 않으므로, 한 정점에서 다른 정점으로 갈 수 있는 방법(경로로써의 경우의 수)은 단 1가지뿐이다. (중요 3-1)
// 즉, 혹시나 또다른 더 빠른 고속도로 간선이있는가하고 직통길이 존재하는지 의심할 필요가 없다. (중요 3-2)
// 어차피 경로의 경우의 수는 1가지뿐이기에, 멀리있으면 직통길없이 일일이 노드들을 타고타고 가야만 한다. (중요 3-3)
// 하나의 노드에 자식 노드가 여러개일 수 있다.
// 루트 노드는 존재할 수도 있지만, 아니면 따로 존재하지않고 그저 그래프 형태처럼 생길 수도 있다.
// 기본적으로 트리는 그래프의 특별한 한 종류이기 때문에, BFS 및 DFS 알고리즘을 적용시킬 수 있다.

// - 문제이해 팁:
// 문제에서 노드의 개수는 N개이고, 다음 N-1개의 줄에 트리상에 연결된 두 점을 입력해준다고 했다.
// 이는 트리의 성질을 비추어보았을때, 모든 간선을 알려준다는 의미이므로, 혹시나 연결된 또다른 간선은 없는지 추가적으로 의심할 필요가 없다.
// 이에 더불어, 사이클이 존재하지 않으므로, 직통길없이 한 정점에서 다른 정점까지의 경로로써의 경우의 수는 단 1가지 뿐임을 명심하자.

// adj[start]에 {그다음정점, 거리} 이렇게 push_back 된다.
vector<pair<int,int>> adj[1002];  // 이거 구조 특이함. 값꺼낼땐 마치 'vector<vector<pair<int,int>>> adj'와 동일함.
int dist[1002] = { 0, };

void bfs(int start) {
    if(dist[start] > 0) return;

    queue<int> qu;
    qu.push(start);
    dist[start] = 1;

    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for(auto nextAdj : adj[cur]) {
            int next = nextAdj.first;
            
            if(dist[next] > 0) continue;

            qu.push(next);
            dist[next] = dist[cur] + nextAdj.second;
        }
    }
}

// 밑은 가독성 좋은 버전의 bfs함수이다.
// void bfs(int x) {
//     if(dist[x] > 0) return;

//     queue<int> qu;
//     qu.push(x);
//     dist[x] = 1;

//     while(!qu.empty()) {
//         int cur = qu.front();
//         qu.pop();

//         for(auto nextAdj : adj[cur]) {
//             int nx = nextAdj.first;
            
//             if(dist[nx] > 0) continue;

//             qu.push(nx);
//             dist[nx] = dist[cur] + nextAdj.second;
//         }
//     }
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int start, end, betweenDist;

    for(int i=0; i<n-1; i++) {
        cin >> start >> end >> betweenDist;

        adj[start].push_back({end, betweenDist});  // 이렇게되면 adj[start]에 여러 pair가 쌓이므로, 차후엔 adj[주요인덱스][쌓이는만큼인덱스].first 이런식으로 불러내야한다.
        adj[end].push_back({start, betweenDist});  // 이렇게되면 adj[end]에 여러 pair가 쌓이므로, 차후엔 adj[주요인덱스][쌓이는만큼인덱스].first 이런식으로 불러내야한다.
    }

    while(m--) {
        cin >> start >> end;

        bfs(start);
        cout << dist[end] - 1 << "\n";  // 애초에 dist값을 1이 아닌 0으로 시작했기에, 결과 출력할때는 -1 해주고 출력해야한다.

        fill(&dist[0], &dist[1002], 0);
    }


    return 0;
}