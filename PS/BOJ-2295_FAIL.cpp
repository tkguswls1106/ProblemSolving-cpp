// < 시간초과 FAIL 코드 >
// 답은 알맞게 나오는듯 하지만, 시간초과가 난다.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> v;
    vector<long long> temp;
    unordered_set<long long> s;
    long long maxSum = 0;
    long long input;

    int cnt;
    for(int i=0; i<n; i++) {
        cin >> input;
        s.insert(input);
        if(i<3) temp.push_back(0);

        cnt = 3;
        while(cnt--) {
            v.push_back(input);
            if(!(i<3)) temp.push_back(1);
        }
    }
    cnt = v.size() - temp.size();
    while(cnt--) {
        temp.push_back(1);
    }

    sort(v.begin(), v.end());
    do {
        long long sum = 0;
        for(int i=0; i<v.size(); i++) {
            if(temp[i] == 0) sum += v[i];
        }
        if(s.count(sum)) maxSum = max(maxSum, sum);
    } while(next_permutation(temp.begin(), temp.end()));

    cout << maxSum;


    return 0;
}