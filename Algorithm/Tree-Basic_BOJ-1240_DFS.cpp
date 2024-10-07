// - 트리 문제 (DFS 방식) -

#include <vector>
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
int visited[1002] = { 0, };

int finalEnd;
void dfs(int start, int distSum) {
    if(start == finalEnd) {
        cout << distSum << "\n";
        return;
    }

    for(auto nextAdj : adj[start]) {
        int next = nextAdj.first;
        int dist = nextAdj.second;

        if(visited[next] == 1) continue;

        visited[next] = 1;
        dfs(next, distSum + dist);
        // 이 문제의 경우에는 여기서 'visited[next] = 0'를 작성하지않아도 된다. (왜냐면, 이건 백트래킹으로써의 push&pop 으로 되돌아가는 용도의 dfs가 아니기때문임.)
        // - 주의: 백트래킹의 dfs에서만 "'push & visited=1 & dfs호출' 이후 'pop & visited=0'" 이러한 과정을 거치기때문에,
        // 이처럼 백트래킹이 아닌 일반적인 dfs를 사용하는 문제의 경우에는, 어차피 백트래킹처럼 pop으로 되돌아가질 않기때문에, 차후 pop이나 visited=0 의 과정은 작성하지 말아야한다.
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int start, end, dist;

    for(int i=0; i<n-1; i++) {
        cin >> start >> end >> dist;

        adj[start].push_back({end, dist});  // 이렇게되면 adj[start]에 여러 pair가 쌓이므로, 차후엔 adj[주요인덱스][쌓이는만큼인덱스].first 이런식으로 불러내야한다.
        adj[end].push_back({start, dist});  // 이렇게되면 adj[end]에 여러 pair가 쌓이므로, 차후엔 adj[주요인덱스][쌓이는만큼인덱스].first 이런식으로 불러내야한다.
    }

    while(m--) {
        cin >> start >> end;
        finalEnd = end;

        visited[start] = 1;  // 이 문제의 dfs는 백트래킹과 다른 dfs이므로, 사실상 이처럼 먼저 visited=1을 선언하고 가도 좋다.
        dfs(start, 0);

        fill(&visited[0], &visited[1002], 0);
    }


    return 0;
}