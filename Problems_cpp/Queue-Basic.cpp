#include <queue>
#include <iostream>

using namespace std;

// [ 큐 기초 정리 ]

int main()
{
    // queue에서는 front와 back말고는 안의 원소들의 내용은 바로 확인하지 못한다.

    // 큐 선언
    queue<int> qu;

    // 뒤로 추가
    qu.push(1); // 앞 1 뒤
    qu.push(2); // 1 2
    qu.push(3); // 1 2 3
    qu.push(4); // 1 2 3 4

    // 가장 앞 front 원소 삭제 (큐가 비어있다면 에러 발생.)
    qu.pop(); // 2 3 4

    // 가장 앞 원소 반환 (큐가 비어있다면 에러 발생.)
    cout << qu.front() << "\n"; // => 2

    // 가장 뒷 원소 반환 (큐가 비어있다면 에러 발생.)
    cout << qu.back() << "\n"; // => 4

    // 큐 길이 반환
    cout << qu.size() << "\n"; // => 3

    // empty를 활용한 원소 출력 응용
    while (!qu.empty()) // 큐가 비어있지않을때
    {
        cout << qu.front() << " "; // => 2 3 4
        qu.pop();
    }
    cout << "\n";


    return 0;
}