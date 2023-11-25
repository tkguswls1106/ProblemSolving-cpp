#include <list>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int num;
    cin >> str >> num;

    list<char> li;
    for(auto ch : str) li.push_back(ch);
    auto iter = li.end();

    // 디폴트로, 커서 뒤가 iter라고 생각하면 편함.

    while(num--) {
        char op;
        cin >> op;
        if(op == 'L') {
            if(iter != li.begin()) iter--;
        }
        else if(op == 'D') {
            if(iter != li.end()) iter++;
        }
        else if(op == 'B') {
            if(iter != li.begin()) {
                iter--;
                iter = li.erase(iter);  // erase하고 iter로 반환할당해주는거 잊지말기!
            }
        }
        else {  // op == 'P'
            char addCh;
            cin >> addCh;  // 여기서 입력을 받아도 백준에서는 스페이스바 입력이나 엔터입력이나 같게 취급하여 상관없음.
            li.insert(iter, addCh);  // insert는 어차피 iter위치의 앞부분에 삽입임.
        }
    }

    for(auto l : li) cout << l;
}