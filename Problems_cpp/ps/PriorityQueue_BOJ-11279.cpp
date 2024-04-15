#include <queue>
#include <iostream>

using namespace std;

// - 사용할 알고리즘 찾기:
// "'가장' 큰 숫자를 출력하고, 이를 배열에서 제외한다." 라고 문제에서 명시했으므로,
// 이는 우선순위큐가 적합함을 알 수 있다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq;
    
    int cnt, x;
    cin >> cnt;
    while(cnt--) {
        cin >> x;
        if(x != 0) pq.push(x);
        else {
            if(pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }


    return 0;
}