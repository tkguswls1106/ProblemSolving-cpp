#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// 유니온파인드 문제이지만, 입력되는 숫자가 작기에 다른 방식으로 풀었음.

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m, man, input;
	cin >> n >> m >> man;
	unordered_set<int> s;
	vector<pair<vector<int>, bool>> vv;

	while(man--) {
		cin >> input;
		s.insert(input);
	}

	while(m--) {
		cin >> man;
		bool isKnow = false;
		vector<int> v;

		bool isTruth = false;
		while(man--) {
			cin >> input;
			if(s.count(input) != 0) isTruth = true;
			v.push_back(input);
		}

		if(isTruth == true) s.insert(v.begin(), v.end());
		else vv.push_back({v, false});
	}

	int falseCnt1 = vv.size();
	int falseCnt2;
	while(true) {

		for(int i=0; i<vv.size(); i++) {
			if(vv[i].second == true) continue;

			bool isTruth = false;
			for(int j=0; j<vv[i].first.size(); j++) {
				if(s.count(vv[i].first.at(j)) != 0) isTruth = true;
			}

			if(isTruth == true) {
				s.insert(vv[i].first.begin(), vv[i].first.end());
				vv[i].second = true;
			}
		}

		int cnt = 0;
		for (auto p : vv) {
			if (p.second == false) {
				cnt++;
			}
		}
		falseCnt2 = cnt;
		if(falseCnt1 == falseCnt2) break;
		else swap(falseCnt1, falseCnt2);
	}

	cout << falseCnt2;
	

	return 0;
}