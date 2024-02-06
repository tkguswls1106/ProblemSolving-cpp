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
    int slice = lock.size() / key.size();

    vector<pair<char,int>> sortKeyV;
    for(int i=0; i<key.length(); i++) {
        sortKeyV.push_back({key[i], i});  // {i, key[i]} 말고 {key[i], i} 순으로 넣기.
    }
    sort(sortKeyV.begin(), sortKeyV.end());

    char answer[102][102];
    for(int i=0; i<sortKeyV.size(); i++) {
        for(int j=0; j<slice; j++) {
            int idx = sortKeyV[i].second;
            answer[j][idx] = lock[i*slice + j];  // 이 부분 헷갈리지 말기!
        }
    }

    for(int i=0; i<slice; i++) {
        for(int j=0; j<key.size(); j++) {
            cout << answer[i][j];
        }
    }


    return 0;
}