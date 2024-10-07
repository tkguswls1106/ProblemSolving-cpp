#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// - 주의사항:
// 삼각형이 되기위한 조건인 '가장 큰 변의 길이 < 나머지 두 변의 길이 합'임을 명심하고 풀자.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, input;
    cin >> n;
    vector<int> v;

    while(n--) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.rbegin(), v.rend());  // 내림차순 정렬

    for(int i=0; i<v.size()-2; i++) {
        if(v[i] < v[i+1] + v[i+2]) {  // '가장 큰 변의 길이 < 나머지 두 변의 길이 합'으로 삼각형이 되기위한 조건을 충족했을 경우
            cout << v[i] + v[i+1] + v[i+2];
            return 0;
        }
        // " i++로 인해 세변이 'v[i+1],v[i+2],v[i+3]' 이 되는 경우가 될수 있지만, 그렇다면 'v[i],v[i+1],v[i+3]'는 왜 확인하지 않는걸까? "
        // 위의 헷갈릴만한 점을 근거와 함께 설명해보자면,
        // 어차피 if(v[i] < v[i+1] + v[i+2]) 이 조건을 충족하지 못한경우라면, v[i+2] 대신 더 작은 v[i+3] 을 넣더라도 똑같이 두변의 길이합이 v[i]보다 작을 것이기에,
        // 결국 이전과 마찬가지로 조건이 충족되지 않기에, 의미가 없는 행위이므로 확인하지 않아도 된다.
    }
    cout << -1;
    

    return 0;
}