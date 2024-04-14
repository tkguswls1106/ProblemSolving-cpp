#include <queue>
#include <iostream>

using namespace std;

// - 사용할 알고리즘 찾기:
// "큐인데, 중요도를 따져서 인쇄시킨다." 라고 문제에서 명시했으므로,
// 이는 우선순위큐가 적합함을 알 수 있다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        queue<pair<int,int>> qu;  // <문서번호, 중요도>
        priority_queue<int> pq;  // 최대힙 우선순위큐

        int n, m;
        cin >> n >> m;

        for(int i=0; i<n; i++) {
            int imp;
            cin >> imp;
            qu.push({i,imp});
            pq.push(imp);
        }

        int cnt = 0;
        while(!qu.empty()) {
            int curIdx = qu.front().first;
            int curImp = qu.front().second;
            qu.pop();

            int top = pq.top();
            if(curImp == top) {  // 중요도가 같은 문서가 여러개일수도 있으므로, 이 if문 안에 또다른 if문으로 걸러주어야한다.
                pq.pop();
                cnt++;

                if(curIdx == m) {  // 중요도가 같은동시에, 위치도 같을 경우
                    cout << cnt << "\n";
                }
            }
            else {
                qu.push({curIdx, curImp});
            }
        }
    }


    return 0;
}