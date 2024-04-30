// - 공간 메모리 제한 문제 (우선순위큐 방식) -
// '우선순위큐' 문제이지만, 'array배열 정렬'로도 풀 수 있는 문제임.
// 참고로 이 코드는 우선순위큐 방식을 사용하였음.
// 배열 정렬 방식은 'Sort_BOJ-2075.cpp'에 있음.

#include <queue>
#include <iostream>

using namespace std;

// - 사용할 알고리즘 찾기:
// 큰순서와 값을 전부 다 알필요없이, 그저 N번째 큰 수를 찾으면 되므로,
// vector 정렬 또는 set보다 빠른 우선순위큐를 활용하는것이 좋을것으로 예상됨.
// ==> 우선순위큐 사용.

// - 메모리 초과 계산:
// int형은 4바이트이므로, 1500x1500x4바이트 = 900만 바이트 (900만 Byte)
// = 900만/1024 킬로바이트 = 약 900만/1000 킬로바이트 = 약 9000 킬로바이트 (9000 KB)
// = 9000/1024 메가바이트 = 약 9000/1000 메가바이트 = 약 9메가바이트(9 MB)
// 9MB이므로 그렇다면 사실상 문제에서 주어진 메모리 제한 12MB를 넘지않는다.
// ==> 그저 우선순위큐에 전부 넣고 풀어도된다는 의미. (!!! 하지만 이렇게 풀면 이상하게도, 추가적으로 사용되는 메모리가 있는지 메모리초과 에러가 뜬다. 이렇게 풀지 말것. !!!)

// - 문제 풀이방법:
// N번째 큰수 라는 것은 N개만 가지고 있는 우선순위큐에서 최소값을 찾는 것과 같은 의미이다.
// 그렇기에, 우선순위큐를 최대힙이 아닌 최소힙으로 선언하고, 우선순위큐의 크기가 N을 넘지않도록 그때마다 매번 가장 작은 숫자를 pop() 해줌으로써 메모리를 절약하면,
// 메모리초과가 뜨지않게 될 뿐만아니라, 결국 최종적으로는 'N번째 숫자(우선순위큐에서 최소값) ~ 최댓값'만 남게되어, 성공적인 문제 풀이가 가능해진다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;  // 최소힙 우선순위큐 (오름차순)
    
    int n, input;
    cin >> n;
    int cnt = n*n;
    while(cnt--) {
        cin >> input;
        pq.push(input);
        if(pq.size() > n) pq.pop();  // 우선순위큐 크기가 N이 넘어갈때마다, 가장 작은 숫자(가장 우선순위가 높음)를 pop() 해줌.
        // 그러면 결국 최종적으로는 'N번째 숫자(우선순위큐에서 최소값) ~ 최댓값'만 남게됨.
    }

    cout << pq.top();


    return 0;
}