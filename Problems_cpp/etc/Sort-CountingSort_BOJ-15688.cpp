#include <map>
#include <iostream>

using namespace std;

// 수의 범위가 작기때문에 카운팅정렬을 사용해도 좋다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int, int> m;

    int n;
    cin >> n;
    while(n--) {
        int input;
        cin >> input;
        m[input]++;
    }

    for(auto iter=m.begin(); iter!=m.end(); iter++) {
        int cnt = iter->second;
        while(cnt--) {
            cout << iter->first << "\n";
        }
    }


    return 0;
}