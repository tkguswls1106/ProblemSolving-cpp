// < 아쉬운 PASS 코드 >
// - 놓쳤던 부분:
// pair을 활용하여, 보다 효율적이고 짧은 코드로 변경할 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string key, lock;
    cin >> key >> lock;

    string sortKey = key;
    sort(sortKey.begin(), sortKey.end());
    int slice = lock.size() / key.size();

    vector<string> v;
    int keyIdx = 0;
    int idx = 0;
    while(idx < lock.size()) {
        string str = "";
        str += sortKey[keyIdx];
        str += lock.substr(idx, slice);

        v.push_back(str);
        keyIdx++;
        idx += slice;
    }

    vector<string> v2;
    for(int i=0; i<key.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(key[i] == v[j][0]) {
                string str = "";
                for(int k=1; k<=slice; k++) str += v[j][k];
                v2.push_back(str);

                v[j][0] = '1';
                break;
            }
        }
    }

    idx = 0;
    while(idx < slice) {
        for(string str : v2) {
            cout << str[idx];
        }
        idx++;
    }


    return 0;
}