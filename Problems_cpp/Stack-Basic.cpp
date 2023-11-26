#include <stack>
#include <iostream>

using namespace std;

// [ 스택 기초 정리 ]

int main() {
    // stack에서는 top말고는 그 밑의 원소들의 내용은 바로 확인하지 못한다.

    // 스택 선언
    stack<int> st;

    // 위로 쌓아가면서 추가
    st.push(1);  // 밑 1 위
    st.push(2);  // 1 2
    st.push(3);  // 1 2 3
    st.push(4);  // 1 2 3 4

    // 가장 윗 원소 삭제
    st.pop();  // 1 2 3

    // 가장 윗 원소 반환
    cout << st.top() << "\n";  // => 3

    // 스택 길이 반환
    cout << st.size() << "\n"; // => 3

    // empty를 활용한 원소 출력 응용
    while (!st.empty())
    {
        cout << st.top() << " ";  // => 3 2 1
        st.pop();
    }
    cout << "\n";
    

    return 0;
}