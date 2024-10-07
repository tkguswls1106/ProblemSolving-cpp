#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());  // 오름차순 정렬
    
    int cnt = 0;
    int sIdx = 0, eIdx = people.size() - 1;
    while(sIdx < eIdx) {
        if(people[sIdx] + people[eIdx] <= limit) {  // 최솟값+최댓값 둘이 탐.
            sIdx++;
            eIdx--;
        }
        else {  // 최댓값 혼자 탐. (혼자서 limit 채움)
            eIdx--;
        }
     
        cnt++;  // 혼자타든 둘이타든, while문 돌때마다 어차피 구명보트 1개씩 반드시 사용함.
    }
    if(sIdx == eIdx) cnt++;  // 남은 혼자 탐.
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}