// - 백트래킹 수열 NM 11번 문제 -
// 이는 나름의 내 방식대로 변형하여 풀은 코드이다.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;  // 고른 숫자들 담을 배열
vector<int> iV;  // 고를 숫자 종류들 담을 배열

// 아마도 밑의 func함수를 dfs함수로도 칭하는듯하다?
void func(int k) {  // k = 현재 이미 골라서 저장되어있는 개수
    if(k == m) {
        for(int num : v) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for(int i : iV) {  // 이문제는 타문제처럼 1~N 자연수 오름차순 순서대로 넣어주는것이 아니므로 차후 출력시 사전순 정렬이 되게하려면, 메인함수에서 sort를 해주는것이 옳다.

        v.push_back(i);
        func(k+1);  // 어차피 처음 시작할때 k=0부터 파라미터를 넣어주었기때문에, 만약 k+1이 m과 같아진다면 이외 코드실행없이 바로 출력이되고 return;이 실행되며 최근 재귀가 종료된다.

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
        iV.push_back(input);
    }
    sort(iV.begin(), iV.end());  // unique전에 sort를 해주어야 전체적으로 중복이 사라진다.
    iV.erase(unique(iV.begin(),iV.end()), iV.end());  // 어차피 같은수를 여러번골라도 되는 조건이 있으므로, 중복을 미리 삭제하고가도 전혀 문제없게된다.
    // 하지만 위의 두 코드줄의 과정은 iV라는 vector대신에 set를 활용하면 줄일수있을듯하다. (예시는 내 코드인 BackTracking-Sequence_BOJ-15666)

    func(0);


    return 0;
}