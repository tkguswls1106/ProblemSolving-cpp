#include <stack>
#include <iostream>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        string str;
        getline(cin, str);
        if(str == ".") break;

        stack<char> st;
        for(char ch : str) {
            if(ch=='(' || ch=='[') {
                st.push(ch);
            }
            else if(ch==')' || ch==']') {
                if(st.empty()) {
                    cout << "no" << "\n";
                    break;
                }
                else if((st.top()=='(' && ch==']') || (st.top()=='[' && ch==')')) {
                    cout << "no" << "\n";
                    break;
                }
                else {
                    st.pop();
                }
            }
            else if(ch == '.') {
                if(ch == '.') {
                    if(st.size() == 0) cout << "yes" << "\n";
                    else cout << "no" << "\n";
                }
            }
        }
    }
}