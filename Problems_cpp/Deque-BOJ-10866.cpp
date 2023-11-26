#include <deque>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;

    int num;
    cin >> num;

    while(num--) {
        string str;
        cin >> str;

        int n;
        if(str == "push_front") {
            cin >> n;
            dq.push_front(n);
        }
        else if(str == "push_back") {
            cin >> n;
            dq.push_back(n);
        }
        else if(str == "pop_front") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(str == "pop_back") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(str == "size") {
            cout << dq.size() << "\n";
        }
        else if(str == "empty") {
            cout << int(dq.empty()) << "\n";
        }
        else if(str == "front") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else {  // str == "back"
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
    }
}