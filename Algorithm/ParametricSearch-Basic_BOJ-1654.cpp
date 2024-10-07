// - 매개변수 탐색 문제 -

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// [ 매개변수 탐색 - 백준 1654 문제 ]

// - 매개변수 탐색(Parametric Search) 이란?:
// 이분(이진) 탐색을 사용하여 조건을 만족하는 최댓값 또는 최솟값을 구하는 알고리즘이다.
// 하지만 매개변수 탐색의 경우에는, 이분탐색 관련 STL 함수를 사용할 수 없고 직접 이분탐색을 구현하여 응용해야 한다.
// '최적화 문제'를 '결정 문제'로 바꾸어서 풀 수 있다.
// 참고로 최적화 문제란, 여러 개의 해답 중에서 주어진 조건을 만족하는 최적의 해답을 찾는 문제이다.
// 그리고 결정 함수란, 조건을 만족하면 true를, 만족하지 않으면 false를 반환하는 함수로써, 반환 값에 따라서 검사 범위를 변경하게 된다.

// 이 문제의 경우 매개변수 탐색을 적용하면, 랜선의 길이를 x로 두고나면 잘려진 개수를 구하는건 O(K)이고 랜선의 길이로 가능한 범위는 2^31이기에,
// 시간복잡도는 O(K * log2^31) = O(31K) = 최대 31*10000 = 최대 310000번의 연산횟수 < 2억번 연산횟수(2초) 이므로, 문제 풀이에 가능해진다.
// 참고로 2^31에다가 이진탐색을 적용했기에 log2^31 인것이다.

vector<int> v;
int k, n;

// 그래프의 x축값: 잘려진 각 랜선의 길이, y축값: 잘려서 나온 총 랜선의 개수
bool cut(long long x) {  // 결정함수 (조건 만족시 true, 불만족시 false)
    long long curN = 0;  // 잘려서 나온 총 랜선의 개수 (그래프 끝으로 갈수록 2^31까지 무한정으로 늘어나기에, long long 자료형이어야만 함.)
    for(int num : v) {
        curN += (num / x);
    }

    // curN이 더 크다는 건 x가 작다는 의미
    // (= 잘려서 나온 총 랜선의 개수가 더 많게 나왔다는건, 문제 조건에 충족한다는 의미임. 그렇기에 잘려진 각 랜선의 길이를 더 길게해서 실험해봐도 됨.)
    return curN >= n;  // curN>=n이 맞다면 결정함수 true 반환. 그렇지않다면 false 반환.
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    while(k--) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    long long start = 1;
    long long end = *max_element(v.begin(), v.end());  // 어차피 최대로 나올수있는 잘린 랜선 하나의 길이는, 이미 존재하는 랜선중 가장 긴 랜선보다 같거나 작을수밖에 없다.

    while (start < end) {  // start가 end를 넘어서는 순간, 이는 이분탐색이 종료된 시점을 의미한다.
        long long mid = (start + end + 1) / 2;  // 'mid = (start + end)/2'로 두면, start와 end가 1 차이날 때(예시로 start=4,end=5 일때) start가 계속 값이 똑같아 무한루프에 빠질수있다.
        if (cut(mid)) {  // 결정함수 호출로 조건 판단. (이분탐색 STL없이 직접 구현)
            start = mid;  // 그래프 x축값인 잘린 랜선 하나의 길이를 더 길게해서 실험해봐도 됨.
        }
        else {
            end = mid - 1;  // 그래프 x축값인 잘린 랜선 하나의 길이를 더 짧게해야만 조건을 충족할 수 있음.
        }
    }
    cout << start;


    return 0;
}