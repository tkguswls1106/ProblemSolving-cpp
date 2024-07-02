#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());  // 최소힙
    
    int cnt = 0;
    int top1, top2;
    while(pq.size() >= 2) {
        if(pq.top() >= K) return cnt;
        
        top1 = pq.top();
        pq.pop();
        top2 = pq.top() * 2;
        pq.pop();
        
        pq.push(top1 + top2);
        cnt++;
    }
    
    if(!pq.empty() && pq.top() >= K) return cnt;
    else return -1;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}