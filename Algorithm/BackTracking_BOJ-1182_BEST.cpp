#include <vector>
#include <iostream>

using namespace std;

int n,s;
vector<int> iV;  // 전체 수열

int cnt = 0;
void func(int k, int sum) {
    if(k == n) {  // 안더해도 k+1을 해주므로 개수는 최종적으로 k가 n이 되긴 해야함.
        if(sum == s) {
            cnt++;
        }
        return;
    }

    // 이 문제는 가짓수당 각각 for문으로 visited를 확인하고 그에 맞춰 수열값들을 모두 더해보는 경우를 구하는것이 아니기때문에,
    // for(int i : iV) 처럼 반복문을 사용하여 그 안에서 sum+i로 재귀함수를 호출하면 안된다.
    func(k+1, sum);  // 현재 인덱스의 수를 더하지 않는 경우
    func(k+1, sum + iV[k]);  // 현재 인덱스의 수를 더하는 경우
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

    func(0, 0);
    if(s == 0) cnt--;  // 문제에서 크기가 양수인 부분수열만 센다고 했으므로, s가 0일때 공집합의 경우를 제외하기위해 cnt를 하나 빼줘야한다.
    cout << cnt; 


    return 0;
}