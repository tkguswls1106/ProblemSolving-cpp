#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

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