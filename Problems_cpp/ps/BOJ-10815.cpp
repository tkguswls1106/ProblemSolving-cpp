#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_set<int> s;
    int n,m,input;

    cin >> n;
    while(n--) {
        cin >> input;
        s.insert(input);
    }

    cin >> m;
    while(m--) {
        cin >> input;
        if(s.count(input)) cout << 1 << " ";
        else cout << 0 << " ";
    }


    return 0;
}