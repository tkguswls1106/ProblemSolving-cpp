#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string s;
    cin >> n >> m >> s;

    int answer = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'I') {

            int nCnt = 0;
            while(s[i+1] == 'O' && s[i+2] == 'I') {
                nCnt++;
                i += 2;  // 참고로 i값의 변화는 가장 외곽쪽의 for문에도 영향을 미친다는 사실을 주의해야한다!
                if(nCnt == n) {
                    answer++;
                    nCnt--;  // 이는 이후에서도 계속 추가로 "OI"가 나올경우에, answer++;이 가능한 상황을 만들기위해, 부분 문자열의 중복을 허용하려고 작성한 것이다.
                }
            }
        }
    }

    cout << answer;


    return 0;
}