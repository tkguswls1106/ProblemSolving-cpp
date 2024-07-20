#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int dist[20002] = { 0, };
queue<int> qu;
unordered_map<int, vector<int>> m;

int maxValue = 1;
void bfs() {
    while(!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        
        if(m.count(cur) == 0) return;
        vector<int> v = m[cur];
        
        for(int next : v) {
            if(dist[next] > 0) continue;
            qu.push(next);
            dist[next] = dist[cur] + 1;
            maxValue = max(maxValue, dist[next]);
        }
    }
}

bool isMax(int n) {
    return n == maxValue;
}

int solution(int n, vector<vector<int>> edge) {
    for(auto v : edge) {
        m[v[0]].push_back(v[1]);
        m[v[1]].push_back(v[0]);
    }
    
    qu.push(1);
    dist[1] = 1;
    bfs();
    
    int cnt = count_if(&dist[1], &dist[20002], isMax);
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}