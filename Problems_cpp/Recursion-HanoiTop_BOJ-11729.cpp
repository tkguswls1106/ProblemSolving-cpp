#include <cmath>
#include <iostream>

using namespace std;

void hanoi(int start, int mid, int end, int n) {  // start:1, mid:2, end:3 이다. 참고로 특히 첫번째와 세번째 매개변수가 가장 중요하다.
    if (n == 1)
    {
        cout << start << " " << end << "\n";
    }
    else
    {
        // < n개의 원반을 1(start)에서 3(end)으로 옮기기 위한 하노이탑 알고리즘 >
        hanoi(start, end, mid, n - 1);  // 과정1. n-1개의 원반을 1(start)에서 2(mid)로 옮김.
        cout << start << " " << end << "\n";  // 과정2. 남은것들중 가장큰 밑의 원반 하나를 1(start)에서 3(end)으로 옮김.
        hanoi(mid, start, end, n - 1);  // 과정3. 옮겨뒀던 n-1개의 원반을 2(mid)에서 3(end)으로 옮김.
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 하노이탑 최소 이동횟수의 공식은 '2^n - 1' 이다. (최소 이동횟수 출력)
    cout << (int)pow(2, n) - 1 << '\n';  // pow 함수 앞에 (int)를 적지 않으면, 입력 최대가 20인 pow 함수의 특성상 오차가 커져서 에러가 발생함.
    // 이동순서 출력
    hanoi(1, 2, 3, n);  // 1을 전부 3으로 옮기고 싶을때


    return 0;
}