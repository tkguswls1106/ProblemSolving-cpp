#include <iostream>

using namespace std;

// - 문제 이해:
// 들어온 비행기의 번호가 만약 a라면, 이 비행기는 1~a 게이트 범위에서만 도킹이 가능하다.
// - 문제풀이 팁:
// 시간초과가 나지않도록 '유니온 파인드'를 활용하여 (참고로 유니온파인드 없이 map같은거 사용하면 시간초과 난다),
// 연속된 비행기 번호를 집합으로 묶고, 루트노드를 집합에서 가장 작은 비행기번호로 선두 지정해주면 된다.
// 그렇게하면 뒷번호에서부터 매번 앞부분의 자리가 비어있는지 선형으로 확인할필요없이, 바로 선두로 이동해서 0(가장앞게이트1의 다음부분)이 아니면 더 넣을수있음을 확인 가능하다.
// - 주의점:
// 평소 유니온파인드 merge()함수 작성하듯이, 무턱대고 'else parent[y] = x;'로 작성하면 안된다.
// 그 이유는 merge(root, root-1); 로 호출하는데, 문제개념상 root의 부모는 root-1가 되어야하므로, 'else parent[x] = y;'로 작성해주어야 한다.

int parent[100002] = { 0, };

int findParent(int x) {
	if(x == parent[x]) return x;
	else return parent[x] = findParent(parent[x]);
}

void merge(int x, int y) {  // merge(root, root-1)로 호출 예정.
	x = findParent(x);
	y = findParent(y);

	if(x == y) return;
	else parent[x] = y;  // 문제개념상 root의 부모는 root-1가 되어야하므로, 'else parent[x] = y;'로 작성해주어야 한다. 여기선 [y]=x 순서로 하면 틀린다.
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int g, p, input;
	cin >> g >> p;

	for(int i=1; i<=g; i++) {
		parent[i] = i;
	}

	int cnt = 0;
	while(p--) {
		cin >> input;
		int root = findParent(input);  // 해당 집합의 선두번호
		if(root == 0) break;  // 어차피 전역변수 선언으로 'parent[0] = 0'가 할당되어있다.

		merge(root, root-1);  // 선두와 선두의 앞부분을 이어줌.
		cnt++;
	}
	cout << cnt;
	

	return 0;
}