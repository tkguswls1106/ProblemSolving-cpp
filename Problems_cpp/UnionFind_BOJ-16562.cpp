#include <iostream>
#include <set>

using namespace std;

// - 문제풀이 팁:
// 비용이 더 낮은걸 부모로 지정함으로써, 루트노드 값을 가져왔을때 연관된 친구들을 최소한의 가격으로 비용지불이 가능하다.

int parent[10002] = { 0, };
int cost[10002] = { 0, };

int findParent(int x) {
    if(x == parent[x])
        return x;
    else
        return parent[x] = findParent(parent[x]);
}

void merge(int x, int y) {
    x = findParent(x);
    y = findParent(y);

    if(x == y) {
        return;
    }
    else {
        // 비용이 더 낮은것을 부모로 설정해서 합집합을 실시해야한다.
        if(cost[x] < cost[y]) {  // x루트노드값이 y루트노드값보다 작을때
            parent[y] = x;  // x를 부모로 설정. (y를 x의 자식으로 설정한채로 합집합 실시.)
        }
        else {
            parent[x] = y;  // y를 부모로 설정.
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++) {
        int money;
        cin >> money;

        parent[i] = i;  // 먼저, 부모값을 자신의값으로 초기화부터 실시.
        cost[i] = money;
    }

    while(m--) {
        int v,w;
        cin >> v >> w;
        if(v == w) continue;  // 자기 자신과 친구일때
        merge(v,w);
    }

    int sum = 0;
    set<int> s;  // 중복을 제거한채로, 최상위 루트노드값들을 넣기 위함임.
    for(int i=1; i<=n; i++) {
        s.insert(findParent(i));
    }
    for(auto iter=s.begin(); iter!=s.end(); iter++) {
        sum += cost[(*iter)];
    }

    if(k >= sum) {
        cout << sum;
    }
    else {
        cout << "Oh no";
    }


    return 0;
}