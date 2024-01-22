#include <iostream>

using namespace std;

int parent[202] = { 0, };

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
        parent[y] = x;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        parent[i] = i;  // 먼저, 부모값을 자신의값으로 초기화부터 실시.
    }

    int input;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> input;
            if(i == j) continue;  // 본인이 본인 도시로 가는경우는 제외해도 좋다.
            if(input == 1) merge(i, j);
        }
    }

    // 처음의 루트노드값이 그다음들의 루트노트값과 같다면, 같은 집합안에 속해있으므로, 경로 안에 모두 포함될 수 있다는 의미가 된다.
    cin >> input;
    int firstCityRoot = findParent(input);
    m--;
    while(m--) {
        cin >> input;
        int nextCityRoot = findParent(input);

        if(firstCityRoot != nextCityRoot) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";


    return 0;
}