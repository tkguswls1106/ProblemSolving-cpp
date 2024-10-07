#include <vector>
#include <queue>

using namespace std;

// 차례로 큐에 넣다가, 가장 먼저 front보다 작은 숫자가 나오는 즉시 턴을 넘김.
// ==> 그 턴이 넘겨지기전 그동안 큐에 쌓여온 숫자들은 어차피 front보다 값이 큼.

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    queue<pair<int,int>> qu;  // <가격, 인덱스>
    
    for(int i=0; i<prices.size(); i++) {  // 비교할 비교자 for문 순회
        // 큐에 쌓여온 숫자들은 어차피 front보다 값이 크기에, 앞을 전부 비워주기.
        while(!qu.empty() && qu.front().first > prices[i]) {  // 주식이 떨어진 경우
            answer[qu.front().second] = i - qu.front().second;
            qu.pop();
        }

        // 주식이 떨어지든 말든 비교자를 push는 해야함. (이 방법말고, 덱을 사용하면 더 효율적임.)
        queue<pair<int,int>> qu2;
        qu2.push({prices[i], i});
        while(!qu.empty()) {
            qu2.push(qu.front());
            qu.pop();
        }
        qu = qu2;
    }
    
    // 위의 for문이 끝났을때 큐에 남은것들은 마지막까지도 주식이 안떨어진것들임.
    while(!qu.empty()) {  // 주식이 마지막까지도 안떨어진 경우
        answer[qu.front().second] = (prices.size()-1) - qu.front().second;
        qu.pop();
    }

    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}