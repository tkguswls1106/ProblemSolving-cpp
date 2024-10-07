#include <stack>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;

    int num;
    cin >> num;

    while(num--) {
        string str;
        cin >> str;

        if(str == "push") {
            int n;
            cin >> n;
            st.push(n);
        }
        else if(str == "pop") {
            if (st.empty()) cout << -1 << "\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(str == "size") {
            cout << st.size() << "\n";
        }
        else if(str == "empty") {
            if(st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else {  // str == "top"
            if (st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
    }
}