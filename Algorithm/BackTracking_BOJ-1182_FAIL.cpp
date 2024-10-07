// < 시간초과 FAIL 코드 >
// - 놓쳤던 부분:
// 아마도 답은 맞게나온다. 하지만 이 코드에서 행한 방식인, 부분집합의 종류를 전부다 만들어서 합이 같은지 확인하는 방법은 시간복잡도가 너무 오래걸린다.
// - 해결 방법:
// 전체수열에서의 각 숫자들을 yes or no로 합에 포함시킬것지 아닌지로 백트래킹으로 내려가고 돌아오며 합을 비교하는 방식으로 풀면 된다.

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int n, s;
int visited[22] = { 0, };
vector<int> v;  // 수열에서 고른 숫자들 담을 배열
vector<int> iV;  // 수열의 모든 숫자 담긴 배열

int cnt = 0;

void func(int k, int selectCnt) {  // k = 현재 이미 골라서 저장되어있는 개수, selectCnt = 수열중 몇개를 골라 부분수열을 만들것인지
    if(k == selectCnt) {
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum == s) {
            cnt++;
        }
        return;
    }

    for(int i=0; i<iV.size(); i++) {
        if(visited[i] == 1) continue;
        if(!v.empty() && v.back() > iV[i]) continue;  // 고른 수열을 정렬해주어야 순서가 바뀐 종류의 중복수열을 막을수있다.
        
        v.push_back(iV[i]);
        visited[i] = 1;
        func(k+1, selectCnt);

        v.pop_back();
        visited[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        iV.push_back(input);
    }

    for(int i=1; i<=iV.size(); i++) {  // 부분집합으로 묶을 수열을 고를 숫자 개수를 변경해줌.
        func(0, i);

        v.clear();
        fill(&visited[0], &visited[22], 0);
    }
    cout << cnt;


    return 0;
}