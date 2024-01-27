// < 시간초과 FAIL 코드 >
// 서브태스크 문제로, 50점을 부여받았다. 그 이유는 나머지 테스트케이스에서 시간 초과가 났기 때문이다.

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

    string p = "";
    while(n--) p += "IO";
    p += "I";

    int idx = 0;
    int cnt = 0;
    while(true) {
        if(idx > s.size()-1) break;

        auto findIdx = s.find(p, idx);  // idx인덱스부터 끝까지 검색.
        if(findIdx == string::npos) break;
        else {
            idx = findIdx + 2;
            cnt++;
        }
    }
    cout << cnt;
    

    return 0;
}