#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

// 문제 특성상 'input 변수'의 자료형을 int로 쓰면 틀린다. long long 자료형을 사용해야한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<long long, int> m;  // map<input변수, cnt변수>
    int n;
    cin >> n;
    while(n--) {
        long long input;
		cin >> input;
		m[input]++;
    }

	long long answer;
	int maxCnt = 0;
	for(auto p : m) {
		long long num = p.first;
		int cnt = p.second;

		if(maxCnt < cnt) {
			maxCnt = cnt;
			answer = num;
		}
		else if(maxCnt == cnt) {
			if(answer > num) answer = num;
		}
	}

	cout << answer;


	return 0;
}