#include <vector>
#include <algorithm>

using namespace std;

// - 문제 해석: 'h번 이상 인용된 논문' = h, 'h편 이상이고' = cntH
// ==> (h >= cntH)

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int cntH;
    int maxCntH = 0;
    
    // 작은값 이상 큰값 이하 개수 구하기 (이분탐색 : 큰값 초과값찾기 - 작은값 이상값찾기)
    for(int h : citations) {
        // 'upper_bound(citations.begin(), citations.end(), citations.back()) - lower_bound' 임.
        // 하지만 어차피 citations.end()는 이상값이 아닌 초과값을 의미하기때문에 upper_bound대신 사용함.
        cntH = citations.end() - lower_bound(citations.begin(), citations.end(), h);
        if(h >= cntH) maxCntH = max(maxCntH, cntH);
    }
    
    return maxCntH;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}