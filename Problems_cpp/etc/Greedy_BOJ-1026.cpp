#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 그리디 알고리즘 관련 문제이지만, 난 솔직히 이게 왜 그리디 소속 문제인지는 잘 모르겠다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a, b;
    int n1, n2, input;
    cin >> n1;
    n2 = n1;

    while(n1--) {
        cin >> input;
        a.push_back(input);
    }
    while(n2--) {
        cin >> input;
        b.push_back(input);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int sum = 0;
    for(int i=0; i<a.size(); i++) {
        sum += a[i] * b[i];
    }
    cout << sum;


    return 0;
}