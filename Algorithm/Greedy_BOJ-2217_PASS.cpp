// - 그리디알고리즘 로프 문제 -

// < 아쉬운 PASS 코드 >
// - 놓쳤던 부분:
// 이것도 꽤나 괜찮은 코드이지만, for문 부분을 보다 좋게 변경할 방법이 있다.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;

    while(n--) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.rbegin(), v.rend());  // 내림차순 정렬

    int answer = 0;
    int k = 0;  // 사용할 로프 개수
    for(int oneWeight : v) {
        k++;
        int allWeight = oneWeight * k;
        answer = max(answer, allWeight);
        // for문으로 순회하며 매번 나오는 oneWeight값은, 그동안 추가했던 로프무게중 가장 작은값이 나오기때문에, 답은 '가장작은로프값을 k번 곱한값'과 비교해주면 된다.
        // 참고로 answer값이 갱신에 성공했다고해서 for문을 중지시키거나 max함수없이 갱신하는 방식을 사용하면 안된다. 그 예시로 그 반례의 경우를 밑에 적어두었다.
        // 반례: input값들이 (15,10,6,5) 일때, 나올수있는 answer값들이 (15,20,18,20)
    }

    cout << answer;


    return 0;
}