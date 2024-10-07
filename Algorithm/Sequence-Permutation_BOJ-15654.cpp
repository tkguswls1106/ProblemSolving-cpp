// - 백트래킹 수열 NM 5번 문제 (순열) -
// 이는 백트래킹 방식으로 풀어도되지만, STL함수를 활용하여 조합 방식으로 풀어보았다.
// 단, 이 방식은 같은수를 여러번 뽑아도될 경우의 문제에는 통하지않는 방식이므로, 이럴땐 원래 백트래킹 방식으로 풀도록 하자.
// 다만 내가 봤을땐, 조합의 경우는 STL방식을, 순열의 경우는 백트래킹방식을 활용하여 문제를 푸는것이 가장 효율적일듯 하다.

#include <vector>
#include <iostream>
#include <algorithm>  // next_permutation 함수를 사용하기위해 선언.

using namespace std;

// - 수열에서 순열(Permutation)이란:
// 순열(Permutation)이란 서로 다른 n개의 원소에서 r개를 뽑아 한 줄로 세우는 부분수열 경우의 수를 의미한다. 이는 '조합처럼 순서가 바뀌면 경우의수로 인정안해주는것'과는 다르게 순서가 바뀌어도 인정된다.
// 즉, 순열은 원소를 한 줄로 세우기 때문에 원소의 종류가 같더라도 순서가 다르면 다른 방법으로 본다는 의미이다.
// 방법은 오름차순 정렬된 전체수열 v배열을 next_permutation함수로 다음 순열로 바꿔줌으로써, 다음수열이 가능하다면 true를 반환하기에 do~while을 활용하면 된다.
// 참고로 next_permutation()을 2중으로 써야하는데 그 이유는,
// '조합인 전체 n개에서 r개를 뽑은 숫자들 구하는 do~while'과 '이렇게 뽑은 r개 숫자에 대해 다시 나열할수있는 수열의 경우의 수를 구하는 do~while'가 함께 구성되어야하기 때문이다.
// - 이 수열 문제가 순열문제인지 조합문제인지 알아차리는 방법:
// 문제에서 '고른 수열은 오름차순이어야한다'라는 말이 없이, 그저 'N개의 자연수 중에서 M개를 고른 수열' 이라고만 명시되어있음 => 부분수열의 의미로써 순서가 바뀌어도 사용가능하다는 의미임
// => 그렇다면 조합이 아닌, 순열을 의미함 => 순열(Permutation) 문제이므로 2중으로 do~while과 next_permutation를 활용하기.

vector<int> v;
vector<int> temp1;  // 순열코드에서 뽑을 조합을 구분할 temp1배열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        v.push_back(input);

        if(i < m) temp1.push_back(0);
        else temp1.push_back(1);
    }

    sort(v.begin(), v.end());
    vector<vector<int>> result;  // 최종 수열들 목록 result배열
    do {
        vector<int> temp2;  // 조합으로 뽑은 수열을 나열할 temp2배열
        for(int i=0; i<v.size(); i++) {
            if(temp1[i] == 0)
                temp2.push_back(v[i]);
        }
        
        do {
            result.push_back(temp2);
        }
        while(next_permutation(temp2.begin(), temp2.end()));  // 조합으로 뽑은 숫자를 순열로 나열할 경우 do~while문
    } while(next_permutation(temp1.begin(), temp1.end()));  // 조합의 경우 do~while문

    sort(result.begin(), result.end());
	for(vector<int> i : result) {
		for(int j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}


    return 0;
}