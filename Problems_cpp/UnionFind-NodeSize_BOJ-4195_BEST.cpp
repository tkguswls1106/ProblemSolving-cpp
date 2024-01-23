#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int parent[200002] = { 0, };
int nodeSize[200002] = { 0, };

int findParent(int x) {
    if(x == parent[x])
        return x;
    else
        return parent[x] = findParent(parent[x]);
}

void merge(int x, int y) {  // nodeSize도 함께 관리.
    x = findParent(x);
    y = findParent(y);

    if(x == y)
        return;
    else {
        parent[y] = x;  // x를 y의 부모로 지정.
        nodeSize[x] += nodeSize[y];  // nodeSize를 부모가 된 x에게 추가해줌.
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc, f;
    cin >> tc;
    while(tc--) {
        cin >> f;
        unordered_map<string, int> m;
        int idx = 0;

        for(int i=0; i<200002; i++) {  // 초기화
            parent[i] = i;
            nodeSize[i] = 1;  // nodeSize도 초기화시켜야함.
        }

        while(f--) {
            string str1, str2;
            cin >> str1 >> str2;

            if(m.count(str1) == 0) m[str1] = idx++;
            if(m.count(str2) == 0) m[str2] = idx++;

            merge(m[str1], m[str2]);
            int rootIdx = findParent(m[str1]);
            int size = nodeSize[rootIdx];

            cout << size << "\n";
        }
    }


    return 0;
}