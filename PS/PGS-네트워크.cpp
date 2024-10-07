#include <vector>

using namespace std;

// 난 DFS/BFS말고 유니온파인드로 풀었음.

int parent[202] = { 0, };

int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void merge(int x, int y) {
    x = findParent(x);
    y = findParent(y);
    
    if(x == y) return;
    else parent[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) continue;
            if(computers[i][j] == 1) {
                merge(i,j);
            }
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(parent[i] == i) cnt++;
    }
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}