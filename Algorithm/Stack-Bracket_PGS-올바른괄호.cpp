#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{    
    stack<char> st;
    for(char ch : s) {
        if(ch == '(') st.push(ch);
        else {  // ch == ')'
            if(st.empty()) return false;
            else st.pop();
        }
    }
    if(st.size() != 0) return false;

    return true;
}

int main()
{
    string str1 = solution("(())()") ? "true" : "false";
    string str2 = solution(")()(") ? "true" : "false";
    string str3 = solution("())((()))(()") ? "true" : "false";

    cout << str1 << "\n";  // => true 출력
    cout << str2 << "\n";  // => false 출력
    cout << str3 << "\n";  // => false 출력


    return 0;
}