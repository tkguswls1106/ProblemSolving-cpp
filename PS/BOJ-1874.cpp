#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 문제 지문의 설명이 별로다. 만약 지문이 이해가 안된다면, 'www.youtube.com/watch?v=byCxMbgzEVM&t=19s' 를 참고하자.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, input;
    cin >> n;
    stack<int> st;
    vector<char> v;

    int maxPush = 0;
    while(n--) {
        cin >> input;

        if(!st.empty() && st.top() == input) {
            st.pop();
            v.push_back('-');
            continue;
        }

        if(input > maxPush) {
            for(int i=maxPush+1; i<=input; i++) {
                st.push(i);
                v.push_back('+');
            }
            st.pop();
            v.push_back('-');
            maxPush = input;
        }
        else {  // input < maxPush 일때
            cout << "NO";
            return 0;
        }
    }

    for(char ch : v) {
        cout << ch << "\n";
    }
    

    return 0;
}