#include <queue>
#include <iostream>

using namespace std;

// PriorityQueue_BOJ-13975.cpp 문제와 비슷하다.

// - 사용할 알고리즘 찾기:
// 가장 작은 묶음 2개를 하나로 뭉쳐야하는것을 계속 반복해야한다. (가장 작은 묶음을 합쳐야한다고 판단한것은 그리디 사고방식이라고 볼 수 있음.)
// => '오름차순으로 정렬해서 앞의 두가지를 합치고, 이를 push하고, 다시 정렬하는것'을 반복해야한다.
// => multiset보단 우선순위큐가 더 편리할것으로 예상됨.
// ==> 우선순위큐 사용.

// - 주의사항:
// 이 문제는 다행히 int 자료형으로 해결되었지만,
// 자료형이 long long 이어야할수도 있었으므로, 늘 문제 풀면서 주의하기!

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소힙 우선순위큐 (오름차순). 자료형 long long 주의!

    int n, input;
    cin >> n;
    while(n--) {
        cin >> input;
        pq.push(input);
    }

    int answer = 0;  // 자료형 long long 주의!
    while(pq.size() > 1) {
        int n1 = pq.top();  // 자료형 long long 주의!
        pq.pop();
        int n2 = pq.top();  // 자료형 long long 주의!
        pq.pop();
        pq.push(n1 + n2);
        answer += (n1 + n2);
    }
    
    cout << answer;


    return 0;
}