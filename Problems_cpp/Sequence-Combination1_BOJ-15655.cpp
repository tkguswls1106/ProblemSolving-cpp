// - 백트래킹 수열 NM 6번 문제 (조합 & next_permutation 사용방식) -
// 이는 백트래킹 방식으로 풀어도되지만, STL함수를 활용하여 조합 방식으로 풀어보았다.
// 단, 이 방식은 같은수를 여러번 뽑아도될 경우의 문제에는 통하지않는 방식이므로, 이럴땐 원래 백트래킹 방식으로 풀도록 하자.
// 다만 내가 봤을땐, 조합의 경우는 STL방식을, 순열의 경우는 백트래킹방식을 활용하여 문제를 푸는것이 가장 효율적일듯 하다.

#include <vector>
#include <iostream>
#include <algorithm>  // next_permutation 함수를 사용하기위해 선언.

using namespace std;

// - 수열에서 조합(Combination)이란:
// 조합(Combination)이란 n개의 원소 중에서 r개를 뽑는 경우의 수를 의미한다. 이는 '순열처럼 순서가 바뀌어도 경우의수로 인정해주는것'과는 다르게 순서가 바뀌면 중복처리 되어 인정안된다.
// 방법은 크기가 n인 배열 temp를 만들어 r개의 원소는 0로, 나머지의 원소는 1로 초기화한다. 즉, temp에서 0이 있는 자리의 원소는 뽑아 포함하고 1이 있는 자리의 원소는 미포함한다는 의미이다.
// 그리고 위의 오름차순 정렬된 temp배열을 next_permutation함수로 다음 순열로 바꿔줌으로써, 오름차순 정렬되어있는 수열인 v배열을 temp배열의 인덱스 내부값이 0인지 고려하여 출력하면 모든 조합의 수를 오름차순으로 정렬 출력 가능하다.
// - 이 수열 문제가 순열문제인지 조합문제인지 알아차리는 방법:
// 문제에서 '고른 수열은 오름차순이어야한다'라고 명시되어있음 => 오름차순 정렬된 상태로 출력해야함 => 순서가 바뀌면 중복처리되어 사용불가능하다는 의미임
// => 그렇다면 부분수열의 의미인 순열이 아닌, 그저 뽑을수있는 경우의 수인 조합을 의미함 => 조합(Combination) 문제이므로 temp와 next_permutation 활용하기.

vector<int> v;
vector<int> temp;

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

        if(i < m) temp.push_back(0);
        else temp.push_back(1);
    }

    sort(v.begin(), v.end());
    do {
        for(int i=0; i<v.size(); i++) {
            if(temp[i] == 0)
                cout << v[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(temp.begin(), temp.end()));


    return 0;
}