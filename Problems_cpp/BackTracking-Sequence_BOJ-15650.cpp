// - 백트래킹 수열 NM 2번 문제 -
// 이는 나름의 내 방식대로 변형하여 풀은 코드이다.

#include <vector>
#include <iostream>

using namespace std;

int n, m;
int visited[10] = { 0, };
vector<int> v;  // 고른 숫자들 담을 배열

// 아마도 밑의 func함수를 dfs함수로도 칭하는듯하다?
void func(int k) {  // k = 현재 이미 골라서 저장되어있는 개수
    if(k == m) {
        for(int num : v) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == 1) continue;  // 같은수를 중복없이 여러번 뽑을 수 없을때 작성하는 코드줄이다. 만약 중복 뽑기 가능 조건이라면, 이 코드줄을 포함하여 visited 관련 코드줄은 전부 제거해도된다.
        if(!v.empty() && v.back() > i) continue;  // 벡터에 숫자가 들어있는데 마지막 숫자가 곧 들어갈 i보다 크다면, 제외하고 건너뛰기. (오름차순 수열)

        v.push_back(i);
        visited[i] = 1;
        func(k+1);

        v.pop_back();
        visited[i] = 0;
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