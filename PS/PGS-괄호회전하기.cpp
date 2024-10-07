#include <string>
#include <stack>
#include <algorithm>

using namespace std;

char getReverse(char ch) {
    if(ch == ')') return '(';
    else if(ch == ']') return '[';
    else return '{';
}

bool isCorrect(string &str) {
    stack<char> st;
    for(char ch : str) {
        if(ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        else {
            if(st.empty()) return false;
            else if(getReverse(ch) != st.top()) return false;
            else st.pop();
        }
    }
    return st.empty();
}

int solution(string s) {
    int cnt = 0, len = s.size();
    while(len--) {
        rotate(s.begin(), s.begin()+1, s.end());
        if(isCorrect(s)) cnt++;
    }
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}