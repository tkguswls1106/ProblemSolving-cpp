#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a,b;
    while(cin >> a >> b) {  // while(true)로 작성하면 백준에서 틀림 처리된다.
        int idx = 0;
        bool isSub = false;

        for(int i=0; i<b.size(); i++) {
            if(b[i] == a[idx]) idx++;
            if(idx == a.size()) {  // 헷갈려서 'a.size()-1'로 작성하면 틀린다.
                isSub = true;
                break;
            }
        }

        if(isSub) cout << "Yes\n";
        else cout << "No\n";
    }
    

    return 0;
}