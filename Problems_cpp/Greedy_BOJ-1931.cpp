// - 그리디알고리즘 회의실배정 문제 (Task Scheduling) -

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// - 문제풀이 팁:
// 특정시간 t 이후에 올 다음 회의를 고르는 기준을, 끝나는 시간이 가장 빠른 회의를 선택하게 하면 된다.
// 단, (2,2)처럼 시작하자마자 끝나는 경우의 회의가 있을수 있으므로, 위의 정렬 우선기준 다음의 두번째 정렬 기준으로는 시작시간이 빠른 기준으로 정렬할 수 있도록 해야한다.
// 그러므로 pair을 활용하여 end,start를 넣어줌으로써 sort()정렬하면 위의 정렬기준 두가지를 모두 충족할 수 있다. 또는 sort에 compare로 커스텀 정렬시키는 방법도 있다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> v;

    int start, end;
    while(n--) {
        cin >> start >> end;
        v.push_back({end, start});  // pair값이 end 다음 start로 오도록 넣어야지, 나중에 sort로 정렬할때 end우선 기준으로 그다음 start 기준으로 오름차순 정렬해준다.
    }
    sort(v.begin(), v.end());

    int t = -1;  // 현재 시간
    int cnt = 0;
    for(auto p : v) {
        start = p.second;
        end = p.first;

        if(t <= start) {  // 현재시간이 다음 회의시작 시간보다는 당연히 같거나 빨라야한다.
            t = end;
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}