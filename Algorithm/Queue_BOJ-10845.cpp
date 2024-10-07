#include <queue>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> qu;

    int num;
    cin >> num;

    while(num--) {
        string str;
        cin >> str;

        if(str == "push") {
            int n;
            cin >> n;
            qu.push(n);
        }
        else if(str == "pop") {
            if (qu.empty()) cout << -1 << "\n";
            else {
                cout << qu.front() << "\n";
                qu.pop();
            }
        }
        else if(str == "size") {
            cout << qu.size() << "\n";
        }
        else if(str == "empty") {
            cout << int(qu.empty()) << "\n";
        }
        else if(str == "front") {
            if (qu.empty()) cout << -1 << "\n";
            else cout << qu.front() << "\n";
        }
        else {  // str == "back"
            if (qu.empty()) cout << -1 << "\n";
            else cout << qu.back() << "\n";
        }
    }
}