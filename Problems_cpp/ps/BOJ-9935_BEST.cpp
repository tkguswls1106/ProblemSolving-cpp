#include <vector>
#include <string>
#include <iostream>

using namespace std;

// - 풀이 방법:
// 문자를 하나씩 넣으면서 마지막 글자가 일치하면 꺼내서 전체 문자열이 일치한지 확인하고 제거하는 방식으로 푼다.

string str, bomb;
vector<char> v;
int bsize = 1;  // 바뀔꺼긴 하지만, 어차피 최소1임.

bool isSame() {
    if(v.size() < bsize) {
        return false;
    }
    else {
        string vStr(v.end()-bsize, v.end());

        if(vStr == bomb) return true;
        else return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> bomb;
    bsize = bomb.size();
    
    for(char ch : str) {
        v.push_back(ch);

        if(ch == bomb.back()) {  // bomb의 마지막 문자와 일치한다면
            if(isSame()) {  // 폭발문자열 검사시 동일한게 맞다면
                for(int i=0; i<bsize; i++) {
                    v.pop_back();
                }
            }
        }
    }

    if(v.size() == 0) cout << "FRULA";
    else cout << string(v.begin(), v.end());


    return 0;
}