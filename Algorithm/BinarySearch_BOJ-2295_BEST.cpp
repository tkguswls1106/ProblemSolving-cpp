#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// - 가능한 방법 3가지:
// 1. 4중 for문 이용하여 모든 경우의 수를 확인하는 방법. 시간복잡도는 O(N^4) => 시간초과
// 2. 가능한 세 수의 합을 구하고, 각 합이 집합 U 안에 존재하는지 이분탐색(logN)으로 확인하는 방법. 시간복잡도는 O(N^3logN) => 시간초과
// 3. twoV은 두 수의 합을 저장한 배열로써, twoV[i] + a[j] = a[k]를 만족하는 a[k]의 최댓값을 이분탐색(logN)으로 구하는 방법. 시간 복잡도는 O(N^2logN)
// => 시간복잡도가 O(N^2logN)이면, 1000^2*10=10000000으로써 연산횟수가 1억번 미만이라 1초내에 풀이가 가능해진다. => 사용가능

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    vector<int> twoV;

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    // 가능한 두 수의 합 구해서 배열에 넣기 (중복 가능하므로, i와 j 모두 범위가 0~n-1 이다.)
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            twoV.push_back(v[i] + v[j]);
        }
    }

    sort(v.begin(), v.end());  // 차후 역순for문에서 큰값부터 찾기위해 미리 정렬해둠.
    sort(twoV.begin(), twoV.end());  // 이분탐색을 위해 이전에 미리 오름차순 정렬시켜야함.

    // 이렇게하면 시간복잡도가 O(N^2logN)로써, 1초내에 풀이 가능.
    for(int i=n-1; i>=0; i--) {  // 세수의합으로 표현할수있는 v배열의 값을 큰값부터 비교함으로써, 가능한 가장 큰 값을 찾음.
        for(int j=i; j>=0; j--) {
            // a + b + c = sum
            // two = a + b 이므로, two + c = sum
            // two = sum - c
            // sum은 v[i] 큰값부터 가능함.
            int sum = v[i], c = v[j];
            int two = sum - c;
            bool isExist = binary_search(twoV.begin(), twoV.end(), two);
            if(isExist == true) {  // if(isExist){} 이렇게 적어도됨.
                cout << sum;
                return 0;
            }
        }
    }


    return 0;
}