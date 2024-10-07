#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.rbegin(), people.rend());  // 내림차순 정렬
    deque<int> dq(people.begin(), people.end());
    
    int cnt = 0;
    int num1;
    while(!dq.empty()) {
        num1 = dq.back();  // 최솟값 고정
        dq.pop_back();
        cnt++;
        
        for(int num2 : dq) {
            dq.pop_front();
            if(num1 + num2 <= limit) break;
            else cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}