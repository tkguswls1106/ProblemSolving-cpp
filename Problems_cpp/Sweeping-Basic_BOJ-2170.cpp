// - 라인 스위핑 문제 -

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// - 스위핑(Sweeping) 이란?:
// '쓸다'라는 뜻이며, 보통 한 쪽 방향부터 시작해서 다른 방향으로 진행하며 탐색하는 과정을 구현하는 것을 의미한다.
// 자료형이 1차원인 경우 라인 스위핑, 2차원인 경우 평면, 3차원인 경우 공간 스위핑이라고 이야기한다.

// - 문제풀이 방법:
// (시작점, 끝점) 형태로 주어지는 Line을 pair로 넣고 오름차순으로 정렬한 후, 왼쪽부터 스위핑하면서 조건에 따라 겹치는 선분들을 병합하며 총 선분의 합을 계산하면 된다.
// 이러한 유형은 크게 밑의 3가지 조건을 생각하면 된다.
// 1. 현재 선분의 시작점이 직전 선분의 끝점보다 크다. (= 두 선분이 겹치지 않는다.)
// 2-1. 현재 선분의 시작점이 직전 선분의 끝점보다 작다. (= 두 선분이 일부가 겹친다.)
// 2-2. 현재 선분의 끝점이 직전 선분의 끝점보다 크다. (= 현재 선분이 직전 선분과 겹치며 그보다 길다.)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<long long, long long>> v;

    for(int i=0; i<n; i++){
        long long x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());  // (시작점, 끝점) 형태로 주어지는 Line을 오름차순으로 정렬

    long long l = v[0].first;  // left
    long long r = v[0].second;  // right
    if(n == 1) {
        cout << r - l;
        return 0;
    }

    long long sum = 0;
    for(int i=1; i<n; i++){
        if(r < v[i].first) {  // 현재 시작점이 직전 끝점보다 큼 (겹치지 않음)
            // 겹치지않는 새로운 선분이므로, sum에 이전까지 겹쳤던 선분의길이를 더해주고, 새로운 선분으로 l과 r의 위치를 갱신시켜줌.
            sum += r-l;
            l = v[i].first;
            r = v[i].second;
        }
        else {  // 현재 시작점이 직전 끝점보다 작음 (겹침)
            if(r < v[i].second) // 현재 끝점이 직전 끝점보다 큼 (선분의 끝을 연장시킴)
                r = v[i].second;
            // 위의 if문이 필요한 이유(반례): {1 4}, {2 3}
        }
    }
    sum += r-l; // 마지막 선분을 sum에 합류시켜 더해줌.
    cout << sum;


    return 0;
}