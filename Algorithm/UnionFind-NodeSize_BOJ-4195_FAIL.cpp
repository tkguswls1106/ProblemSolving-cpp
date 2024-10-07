// < 시간초과 FAIL 코드 >
// - 놓쳤던 부분:
// 아마도 답은 맞게나온다. 하지만 이 코드에서 행한 방식인, 선형적으로 for문을 순회하며 cnt++;하는 방법은 시간복잡도가 너무 오래걸린다.
// - 해결 방법:
// nodeSize배열을 추가로 선언하고, 이를 초반에 1로 초기화하고 merge()함수 내에 응용하여 문제를 푼다.

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int parent[200020] = { 0, };

int findParent(int x) {
    if(x == parent[x])
        return x;
    else
        return parent[x] = findParent(parent[x]);
}

void merge(int x, int y) {
    x = findParent(x);
    y = findParent(y);

    if(x == y)
        return;
    else
        parent[y] = x;
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

        while(f--) {
            string str1, str2;
            cin >> str1 >> str2;

            int isExist = 0;
            if(m.count(str1) == 0) {
                m[str1] = idx;
                parent[idx] = idx;
                idx++;
                isExist = 1;
            }
            if(m.count(str2) == 0) {
                m[str2] = idx;
                parent[idx] = idx;
                idx++;
                isExist = 1;
            }

            merge(m[str1], m[str2]);
            int rootIdx = findParent(m[str1]);
            int cnt = 0;
            for(int i=0; i <= idx - isExist; i++) {
                if(parent[i] == rootIdx) cnt++;
            }
            cout << cnt << "\n";
        }

        fill(&parent[0], &parent[idx + 5], 0);
    }


    return 0;
}