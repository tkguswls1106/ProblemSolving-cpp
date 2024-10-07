#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dist[56] = { 0, };  // 55인덱스는 begin으로 지정하겠음.
queue<pair<string,int>> qu;
vector<string> v;
string t;
int minCnt = 999;

bool isOneDiff(string& a, string& b) {
    int cnt = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) cnt++;
        if(cnt >= 2) return false;
    }
    
    if(cnt == 1) return true;
    else return false;
}

void bfs() {
    
    while(!qu.empty()) {
        pair<string,int> cur = qu.front();
        qu.pop();
        
        for(int i=0; i<v.size(); i++) {
            if(!isOneDiff(cur.first, v[i])) continue;
            if(dist[i] > 0) continue;

            qu.push({v[i], i});
            dist[i] = dist[cur.second] + 1;
            
            if(v[i] == t) {
                minCnt = min(minCnt, dist[i]);
                break;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    t = target;
    v = words;
    
    qu.push({begin, 55});
    dist[55] = 1;
    bfs();
    
    if(minCnt == 999) return 0;
    else return minCnt-1;  // 처음begin을 dist값1로 시작했으므로, 답은 -1을 해준값이어야함.
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}