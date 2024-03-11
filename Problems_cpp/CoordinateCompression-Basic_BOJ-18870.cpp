// - 좌표압축 문제 -

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// [ 좌표압축 - 백준 18870 문제 ]

// - 좌표압축이란?:
// 수의 범위가 매우 크게 주어질 때, 값에 무관하게 단지 대소관계만을 알면 될 때 이용하는 알고리즘이다.
// 기본적으로 해당 알고리즘은 정렬, 이분 탐색을 이용한다.

// 참고로 set에서 distance함수의 시간복잡도가 O(N)이 나오므로, 
// 이 문제의 경우에 'cout << distance(set1.begin(), set1.find(v[i])); << " ";' 이러한 방식으로 코드를 짜면 시간초과가 난다.
// 이분탐색은 절반씩 잘라서 검색하는 방식이므로 시간복잡도가 O(logN)으로 짧다는것을 명심하자.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> originV;  // 기존 배열
    vector<int> v;  // 압축 배열

    int n;
    cin >> n;
    while(n--) {
        int input;
        cin >> input;
        originV.push_back(input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());  // 차후 unique 및 이분탐색 STL함수 사용을 위하여, 그전에 먼저 배열을 오름차순 정렬 시켜줘야만 한다.
    v.erase(unique(v.begin(), v.end()), v.end());  // 중복 제거 (예제입력2 참고)

    for(int i=0; i<originV.size(); i++) {
        int idx = lower_bound(v.begin(), v.end(), originV[i]) - v.begin();  // 예를들어 idx 순서는 0,1,2,3 이런식인데, 2보다 작은것은 0,1 이므로 결국 이는 2개로써 idx인덱스와 같다.
        // 참고로 이문제는 본인값보다 작은 미만값을 구하는 문제이지, 중복카운팅 하는 문제가 아니다. 헷갈리지말자.
        // 틀린코드 ex1: int cnt = upper_bound(v.begin(), v.end(), originV[i]) - lower_bound(v.begin(), v.end(), originV[i]);
        // 틀린코드 ex2: int idx = upper_bound(v.begin(), v.end(), originV[i]) - v.begin();
        cout << idx << " ";
    }


    return 0;
}