#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    // 참고로 밑의방식도 정답처리 되긴함.
    // while(getline(cin, str)) {
    //     cout << str << "\n";
    // }
    while(true) {
        getline(cin, str);
        if(str == "") break;
        cout << str << "\n";
    }

    return 0;
}