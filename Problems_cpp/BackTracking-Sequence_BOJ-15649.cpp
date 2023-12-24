// - 백트래킹 수열 NM 1번 문제 -
// 이는 나름의 내 방식대로 변형하여 풀은 코드이며, 완전 정석의 방법을 원한다면 다음 웹사이트 링크의 코드를 참고하자.
// https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0C/15649.cpp

#include <vector>
#include <iostream>

using namespace std;

// 수열이란, 말그대로 나열한 숫자이지 고르는 가짓수를 구하는것이 아니다. 즉, 수열은 순서에 관계받지않고 모두 경우의수로 취급가능하다는 의미이다.

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
        
        v.push_back(i);
        visited[i] = 1;
        func(k+1);  // 어차피 처음 시작할때 k=0부터 파라미터를 넣어주었기때문에, 만약 k+1이 m과 같아진다면 이외 코드실행없이 바로 출력이되고 return;이 실행되며 최근 재귀가 종료된다.

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