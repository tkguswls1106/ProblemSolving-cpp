#include <vector>
#include <algorithm>  // 이분탐색 STL함수 필요한 헤더
#include <iostream>

using namespace std;

// [ 이분(이진)탐색 기초 정리 ]

// lower_bound와 upper_bound는 이분탐색(Binary Search)을 기반으로 탐색하는 함수이므로, 시간복잡도는 O(logN)이다.
// 이분탐색 알고리즘인 밑의 STL 함수들은 반드시 해당 배열을 오름차순으로 정렬 후에 적용해야만 한다.
// - binary_search(v.begin(), v.end(), num);  // 검색하여 찾는 값이 존재하면 true, 아니면 false를 반환함.
// - lower_bound(v.begin(), v.end(), num);  // 찾고자 하는 값 이상이 처음 나타나는 위치의 iter반복자를 반환함.
// - upper_bound(v.begin(), v.end(), num);  // 찾고자 하는 값의 다음(초과) 값이 최초로 나타나는 위치의 iter반복자를 반환함.
// 참고로 벡터가 아닌 일반배열이라면, 인덱스 구할때 lower_bound(arr, arr + 6, 3) - arr; 뭐 이런식으로도 사용 가능하다.

int main()
{
    vector<int> v = { 5, 3, 1, 5, 5, 10, 8, 8, 10, 13, 11 };
    sort(v.begin(), v.end());  // 이분탐색 이전에 먼저 반드시 배열을 오름차순 정렬시켜야함.
    // 배열 value : { 1, 3, 5, 5, 5, 8, 8, 10, 10, 11, 13 }
    // 배열 index : { 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10 }

    //------------------------------------------------------------------//
    // < binary_search >

    int findValue1 = 5;  // 배열에 존재하는 값
    int findValue2 = 7;  // 배열에 존재하지않는 값

    if(binary_search(v.begin(), v.end(), findValue1) == true) cout << "5 is Exist" << "\n";
    else cout << "5 is not Exist" << "\n";
    // ==> 5 is Exist

    if(binary_search(v.begin(), v.end(), findValue2) == true) cout << "7 is Exist" << "\n";
    else cout << "7 is not Exist" << "\n";
    // ==> 7 is not Exist

    //------------------------------------------------------------------//
    // < lower_bound, upper_bound >

    // 검색값의 이상값이 나타나는 첫 위치 인덱스 (~~ - v.begin())
    cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << "\n";  // ==> 2 (값5는 존재하므로, 해당위치 반환)
    cout << lower_bound(v.begin(), v.end(), 7) - v.begin() << "\n";  // ==> 5 (값7은 존재하지않으므로, 그 다음위치 반환)
    cout << lower_bound(v.begin(), v.end(), 20) - v.begin() << "\n";  // ==> 11 (값20은 존재하지않고 주어진수보다 크므로, 마지막인덱스 다음위치 반환)

    // 검색값의 초과값이 나타나는 첫 위치 인덱스 (~~ - v.begin())
    cout << upper_bound(v.begin(), v.end(), 5) - v.begin() << "\n";  // ==> 5 (값5는 존재하므로, 해당값보다 큰 값의 위치 반환)
    cout << upper_bound(v.begin(), v.end(), 7) - v.begin() << "\n";  // ==> 5 (값7은 존재하지않으며, 해당값보다 큰 값의 위치 반환)
    cout << upper_bound(v.begin(), v.end(), 20) - v.begin() << "\n";  // ==> 11 (값20은 존재하지않고 주어진수보다 크므로, 마지막인덱스 다음위치 반환)

    // 중복값의 개수 구하기
    cout << upper_bound(v.begin(), v.end(), 5) - lower_bound(v.begin(), v.end(), 5) << "\n";  // => 3 (값5의 중복된 개수는 총 3개임.)
    cout << upper_bound(v.begin(), v.end(), 20) - lower_bound(v.begin(), v.end(), 20) << "\n"; // => 0 (값20은 존재하지않고 주어진수보다 크므로, 마지막인덱스 다음위치 - 마지막인덱스 다음위치 = 0)

    // num1이상 num2이하 숫자 개수 구하기 (ex. 5이상 11이하 숫자 개수는?)
    cout << upper_bound(v.begin(), v.end(), 11) - lower_bound(v.begin(), v.end(), 5) << "\n"; // => 8 (참고로 값11이 배열안에 1개가 아니라 2개였다면 출력결과는 9개가 된다.)

    //------------------------------------------------------------------//


    return 0;
}