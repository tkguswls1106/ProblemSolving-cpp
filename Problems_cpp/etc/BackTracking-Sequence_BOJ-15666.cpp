// - 백트래킹 수열 NM 12번 문제 -
// 이는 나름의 내 방식대로 변형하여 풀은 코드이다.

#include <vector>
#include <iostream>
#include <set>

using namespace std;

int n,m;
vector<int> v;  // 고른 숫자들 담을 배열
set<int> s;  // 고를 숫자 종류들 담을 세트

void func(int k) {
    if(k == m) {
        for(int num : v) cout << num << " ";
        cout << "\n";
        return;
    }

    for(auto iter=s.begin(); iter!=s.end(); iter++) {
        int i = *iter;
        if(!v.empty() && v.back() > i) continue;

        v.push_back(i);
        func(k+1);
        
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        s.insert(input);
    }

    func(0);


    return 0;
}