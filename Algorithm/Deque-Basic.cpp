#include <deque>
#include <iostream>

using namespace std;

// [ 덱 기초 정리 ]

void printD(deque<int> dq)
{
    // for문 사용방법중 한가지 예시
    for (int i=0; i<dq.size(); i++)
        cout << dq[i] << " ";
    cout << "\n";
}

int main()
{
    // STL에서의 deque은 마치 vector의 기능에 push_front(넣을값)와 pop_front()를 추가한 자료구조라고 보고 사용해도 무방할듯 하다. 실제로 사용법도 거의 동일하다.
    // 덱(deque)의 실제 개념은, 큐(queue)와 비슷하지만 큐와 다르게 삽입과 삭제가 앞, 뒤 양쪽으로 모두 가능한 자료구조이다.
    // 단, 헷갈리지 말아야할것은 덱에는 push()와 pop()은 없다. 첫번째줄 주석으로 생각하고 덱을 활용하자.

    // 이외의 메소드 사용법은 vector와 매우 유사하니, 이를 대부분 제외하고 작성하겠다.

    // 덱 선언
    deque<int> dq = { 2,2,2 };  // 이외에도 dq(3); dq(3,0); 등등의 벡터와 동일한 방식으로 초기화 방법 사용가능.
    printD(dq);  // => 2 2 2

    // 맨앞에 추가
    dq.push_front(10);
    printD(dq);  // => 10 2 2 2

    // 맨뒤에 추가
    dq.push_back(20);
    printD(dq);  // => 10 2 2 2 20

    // 맨앞을 삭제
    dq.pop_front();
    printD(dq);  // => 2 2 2 20

    // 맨뒤를 삭제
    dq.pop_back();
    printD(dq);  // => 2 2 2

    // 가장 앞 원소 접근 및 할당
    dq.front() = 30;
    printD(dq);  // => 30 2 2

    // 가장 뒷 원소 접근 및 할당
    dq.back() = 40;
    printD(dq);  // => 30 2 40

    // 인덱스로 접근 및 할당
    dq[1] = 50;
    printD(dq);  // => 30 50 40


    return 0;
}