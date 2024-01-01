#include <vector>
#include <iostream>
#include <set>

using namespace std;

int n,m;
vector<int> v;
set<int> s;

void func(int k) {
    if(k == m) {
        for(int num : v)
            cout << num << " ";
        cout << "\n";
        return;
    }

    for(auto iter=s.begin(); iter!=s.end(); iter++) {
        v.push_back(*iter);
        func(k+1);

        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        s.insert(input);
    }

    func(0);


    return 0;
}