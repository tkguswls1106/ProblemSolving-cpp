// < 시간초과 FAIL 코드 >
// - 놓쳤던 부분:
// 답은 알맞게 나오는듯 하지만, 시간초과가 난다.
// find와 erase함수는 시간복잡도가 최대 O(n)이다.
// 그래서 이를 매번 첫인덱스로 돌아가며 find를 하여 erase하는 O(n^2) 시간초과를 방지하기위해, str.find(bomb, idx) 이처럼 활용했다.
// 하지만 이마저도 'if(idx-(size-1) >= 0) idx-=(size-1); else idx = 0;' 이부분 때문인지 46%에서 시간초과가 나게 되었다.
// - 해결 방법:
// 문자를 하나씩 넣으면서 마지막 글자가 일치하면 부분적으로 꺼내서 전체 문자열이 일치한지 확인하고 제거하는 방식으로 푼다.

#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str, bomb;
    cin >> str >> bomb;
    int size = bomb.size();

    int idx = 0;
    while(true) {
        if(str.find(bomb, idx) != string::npos) {
            idx = str.find(bomb, idx);
            str.erase(idx, size);

            if(idx-(size-1) >= 0) idx-=(size-1);
            else idx = 0;
        }
        else break;
    }

    if(str.size() == 0) cout << "FRULA";
    else cout << str;


    return 0;
}