#include <deque>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> dq;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) dq.push_back(i);

    while(dq.size() != 1) {
        // 제일 위에 있는 카드를 바닥에 버림.
        dq.pop_front();

        // 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮김.
        int top = dq.front();
        dq.pop_front();
        dq.push_back(top);
    }

    cout << dq[0];


    return 0;
}