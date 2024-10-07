// < 시간초과 FAIL 코드 >
// 답은 알맞게 나오는듯 하지만, 시간초과가 난다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<int, int>> v;
vector<int> temp;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;
	int limit = n/2;  // ? == limit

	for(int i=1; i<=n; i++) {
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});

		if(i <= limit) temp.push_back(0);
		else temp.push_back(1);
	}
	sort(v.begin(), v.end());  // 이 문제에선 sort안하고 next_permutation 적용시켜도 되긴함.
	
	int minAnswer = 1e9;
	do {
		set<int> setX, setY;  // set안쓰고 그대신, 각좌표의 minX,maxX,minY,maxY값을 구하는 방식으로 풀어도됨.
		for(int i=0; i<v.size(); i++) {
			if(temp[i] == 0) {
				setX.insert(v[i].first);
				setY.insert(v[i].second);
			}
		}

		// map,set같은 연관 컨테이너에서는 iter이동은 증감식으로만 표현해야한다. set.end()-1 이런건 안된다.
		int distX = (*(--setX.end())+1) - (*(setX.begin())-1);
		int distY = (*(--setY.end())+1) - (*(setY.begin())-1);
		minAnswer = min(minAnswer, distX * distY);
	} while(next_permutation(temp.begin(), temp.end()));

	cout << minAnswer;
	

	return 0;
}