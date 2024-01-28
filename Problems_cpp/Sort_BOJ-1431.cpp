#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

// - compare 함수의 반환값이 true일 경우:
// 첫번째 인자가 두번째 인자보다 "작다"는 것을 의미함.
// 이 경우, 첫번째 인자가 두번째 인자보다 앞에 위치하도록 함.
// - compare 함수의 반환값이 false일 경우:
// 첫번째 인자가 두번째 인자보다 "크거나 같다"는 것을 의미함.
// 이 경우, 두번째 인자가 첫번째 인자보다 앞에 위치하도록 함.
// ==> 결론: true면 순서 그대로 유지하고, false면 둘의 순서를 뒤바꾼다.
// 즉, 순서가 원하는대로 오도록 false일경우 뒤바꿔서 재배치하겠다는 의미인것이다.

int getSum(string str) {
    int sum = 0;
    for(char ch : str) {
        if(isdigit(ch)) sum += (ch - '0');
    }
    return sum;
}

bool compare(string& a, string& b) {
    int sumA = getSum(a);
    int sumB = getSum(b);

    if(a.size() != b.size()) {
        return a.size() < b.size();
    }
    else if(sumA != sumB) {
        return sumA < sumB;
    }
    else {
        return a < b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> v;
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);
    for(string str : v)  cout << str << "\n";


    return 0;
}