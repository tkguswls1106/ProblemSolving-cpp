#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_map<int,int> map1;
    int n,m,input;

    cin >> n;
    while(n--) {
        cin >> input;
        map1[input]++;
    }

    cin >> m;
    while(m--) {
        cin >> input;
        if(map1.count(input) == 0) cout << 0 << " ";
        else cout << map1[input] << " ";
    }


    return 0;
}