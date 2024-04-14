#include <queue>  // 우선순위큐도 일반적인 큐와 같은 라이브러리를 사용한다.
#include <iostream>
// #include <vector>
// #include <cmath>

using namespace std;

// [ 우선순위큐(Priority Queue) 기초 정리 ]

// - 우선순위큐 특징:
// * 완전이진트리 형태의 힙 자료구조의 알고리즘이다.
// * 우선순위가 가장 높은 원소의 확인, 원소의 추가, 우선순위가 가장 높은 원소의 제거 이 3개의 기능을 제공한다.
// * 반정렬로써, 전체적인 정렬은 안되어있지만, 최대값 또는 최솟값을 구하기에 매우 적합하다.
// * 중복된 값이 허용된다.

// - 시간 복잡도:
// * 우선순위가 가장 높은 원소 확인: O(1), 원소의 추가: O(logN), 우선순위가 가장 높은 원소 제거: O(logN)
// * priority_queue는 set보다 수행 속도가 빠르고 공간도 적게 차지하기때문에,
//   priority_queue에서 제공하는 연산들만 필요할 경우에는, set을 쓰는것보다 priority_queue를 쓰는게 좋다.

// - priority_queue<> STL 특징:
// * 기본적으로는 최대힙(부모가 자식보다 보다 커야함. 우선순위가 높은 큰 숫자부터 내림차순 정렬)이다. pop()될때는 우선순위가 높은 맨앞의 수부터 삭제된다.
// * 일반적인 큐와는 다르게, 우선순위큐는 qu.front() 말고 pqu.top()을 사용한다.
// * 여기서 cmp는 평소에 사용했던 커스텀 정렬때와는 반대로, return반환값이 true이면 swap한다.
//   예를들어 우선순위큐 전용의 cmp에서, 'if(a < b) return true;' 이면, a<b일때 swap하여 내림차순 정렬을 하겠다는 의미이다.
// * 사용가능 메소드 종류:  push(), pop(), top(), size(), empty()

// 커스텀 우선순위 구조체
struct cmp {
	bool operator() (int n1, int n2) {
        if(abs(n1) != abs(n2)) {
            return abs(n1) > abs(n2);
            // 절댓값기준 오름차순 (절댓값기준 내림차순의 반대.)
            // 절댓값이 작은 것에 우선순위를 높게 주겠다는 의미. (일반적인 커스텀 sort와 반대로 생각할것!)
        }
        else {  // else if(abs(n1) == abs(n2))
            return n1 > n2;
            // 실제값기준 오름차순 (실제값기준 내림차순의 반대.)
            // 절댓값이 같다면, 원래의 실제값이 더 작은 것에 우선순위를 높게 주겠다는 의미. (일반적인 커스텀 sort와 반대로 생각할것!)
        }
    }
};

void printPQ1(priority_queue<int> pq)
{
    while(!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
    // int size = pq.size();
    // for(int i=0; i<size; i++) {  // i<pq.size() 바로 이렇게 써주면 틀린다.
	// 	cout << pq.top() << ' ';
	// 	pq.pop();
	// }
    cout << "\n";
}
void printPQ2(priority_queue<int, vector<int>, greater<int>> pq)
{
    while(!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
    cout << "\n";
}
void printPQ3(priority_queue<int, vector<int>, cmp> pq)  // 이 함수 선언전에, 반드시 cmp 선언이 먼저 되어있어야함.
{
    while(!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
    cout << "\n";
}

int main()
{
    priority_queue<int> pq1;  // 기본 우선순위큐 (최대힙. 내림차순 정렬)
    priority_queue<int, vector<int>, greater<int>> pq2;  // 오름차순 우선순위큐 (최소힙. 오름차순 정렬) (만약 char이면 int들을 전부 char로 변경해주면 됨.)
    priority_queue<int, vector<int>, cmp> pq3;  // 커스텀정렬 우선순위큐 (커스텀 정렬) (만약 char이면 int들을 전부 char로 변경해주면 됨.)

    // pq1
	pq1.push(5);
	pq1.push(1);
	pq1.push(7);
    pq1.push(1);
    printPQ1(pq1);  // => 7 5 1 1

    // pq2
    pq2.push(5);
    pq2.push(1);
    pq2.push(7);
    pq2.push(1);
    printPQ2(pq2);  // => 1 1 5 7

    // pq3
    pq3.push(1);
    pq3.push(-1);
    pq3.push(1);
    pq3.push(-5);
    pq3.push(5);
    pq3.push(8);
    pq3.push(-12);
    printPQ3(pq3);  // => -1 1 1 -5 5 8 -12


    return 0;
}