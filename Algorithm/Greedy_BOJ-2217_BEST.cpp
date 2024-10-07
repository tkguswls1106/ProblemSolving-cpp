// - 그리디알고리즘 로프 문제 -

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
    for(int i=0; i<v.size(); i++) {
        int k = i + 1;  // k는 사용할 로프 개수
        answer = max(answer, v[i] * k);
        // for문으로 순회하며 나오는 v[i]값은, 그동안 추가했던 로프무게중 가장 작은값이 나오기때문에, 답은 '가장작은로프값을 k번 곱한값'과 비교해주면 된다.
    }

    cout << answer;


    return 0;
}