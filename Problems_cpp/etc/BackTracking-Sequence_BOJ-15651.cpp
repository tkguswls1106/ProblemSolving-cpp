// - 백트래킹 수열 NM 3번 문제 -
// 이는 나름의 내 방식대로 변형하여 풀은 코드이다.

#include <vector>
#include <iostream>

using namespace std;

int n, m;
vector<int> v;  // 고른 숫자들 담을 배열

void func(int k) {  // k = 현재 이미 골라서 저장되어있는 개수
    if(k == m) {
        for(int num : v) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++) {

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
    func(0);


    return 0;
}