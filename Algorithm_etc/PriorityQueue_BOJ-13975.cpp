#include <queue>
#include <iostream>

using namespace std;

// PriorityQueue_BOJ-1715.cpp 문제와 비슷하다.

// - 사용할 알고리즘 찾기:
// 가장 작은 묶음 2개를 하나로 뭉쳐야하는것을 계속 반복해야한다. (가장 작은 묶음을 합쳐야한다고 판단한것은 그리디 사고방식이라고 볼 수 있음.)
// => '오름차순으로 정렬해서 앞의 두가지를 합치고, 이를 push하고, 다시 정렬하는것'을 반복해야한다.
// => multiset보단 우선순위큐가 더 편리할것으로 예상됨.
// ==> 우선순위큐 사용.

// - 주의사항:
// 1000000x10000 = 100억으로 int 범위를 초과하므로, 자료형을 반드시 long long으로 사용해야만 한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,k,input;
    cin >> t;
    while(t--) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;  // 최소힙 우선순위큐 (오름차순). 자료형 int쓰면 틀림.
        cin >> k;
        while(k--) {
            cin >> input;
            pq.push(input);
        }

        long long answer = 0;  // 자료형 int쓰면 틀림.
        while(pq.size() > 1) {
            long long n1 = pq.top();  // 자료형 int쓰면 틀림.
            pq.pop();
            long long n2 = pq.top();  // 자료형 int쓰면 틀림.
            pq.pop();
            pq.push(n1 + n2);
            answer += (n1 + n2);
        }
        cout << answer << "\n";
    }


    return 0;
}