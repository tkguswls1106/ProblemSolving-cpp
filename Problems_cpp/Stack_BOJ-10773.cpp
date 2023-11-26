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
        int n;
        cin >> n;

        if(n != 0) st.push(n);
        else st.pop();
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum;
}