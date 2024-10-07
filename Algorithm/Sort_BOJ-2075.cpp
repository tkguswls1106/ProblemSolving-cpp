// - 공간 메모리 제한 문제 (배열 정렬 방식) -
// '우선순위큐' 문제이지만, 'array배열 정렬'로도 풀 수 있는 문제임.
// 참고로 이 코드는 배열 정렬 방식을 사용하였음.
// 우선순위큐 방식은 'PriorityQueue_BOJ-2075_BEST.cpp'에 있음.

#include <algorithm>
#include <iostream>

using namespace std;

// - 메모리 초과 계산:
// int형은 4바이트이므로, 1500x1500x4바이트 = 900만 바이트 (900만 Byte)
// = 900만/1024 킬로바이트 = 약 900만/1000 킬로바이트 = 약 9000 킬로바이트 (9000 KB)
// = 9000/1024 메가바이트 = 약 9000/1000 메가바이트 = 약 9메가바이트(9 MB)
// 9MB이므로 그렇다면 사실상 문제에서 주어진 메모리 제한 12MB를 넘지않는다.
// ==> 그저 배열 및 정렬만으로도 이 문제를 풀 수 있다는 의미.

// (웬만하면 배열의 크기가 큰걸 선언할때에는, 스택메모리가 힙메모리로 넘어와서 segmentation fault가 뜰걸 방지해서 아예 전역변수로 선언해주자.)
int arr[2250002] = { 0, };  // 이를 지역변수로 main함수 내에 작성하거나, vector로 선언하면, segmentation fault 에러가 뜬다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n*n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n*n, greater<int>());
    cout << arr[n-1];


    return 0;
}