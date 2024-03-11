// < 시간초과 FAIL 코드 >
// - 놓쳤던 부분:
// 답은 맞게나옴. 하지만 시간초과가 나는 이유는, 아마도 나는 중복가능한 3번씩 모두 배열에 값을 집어넣고 조합next_permutation을 돌려서 그런것같다.
// - 해결 방법:
// N이 최대 1000이기 때문에, 두수의 합을 미리 합쳐둔 배열을 만들고 이에 이분탐색을 활용하는 방식으로 풀면 된다.
// 이렇게하면, 시간복잡도를 O(N^2logN)인 1000^2*10=10000000으로써 연산횟수가 1억번 미만이라 1초내에 풀이가 가능해진다.

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
    long long input;
    cin >> n;
    vector<long long> v;
    vector<long long> temp;
    unordered_set<long long> s;
    long long maxSum = 0;

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