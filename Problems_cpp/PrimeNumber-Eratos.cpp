#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 문제: 1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하라.
// 풀이방식: '에라토스테네스의 체' 특정 범위내 소수 판별 알고리즘
// 에라토스테네스의 체: i=2부터 시작하여 범위내에서 i의 배수를 모두 제거해주고, i++을 해가며 남은것들에 반복해서 i의 배수를 제거함. 그렇게하면 최종적으로 남은 숫자범위내에는 소수만 남게 됨.

int solution(int n)
{
    vector<bool> tmp(n + 1, true); // 인덱스로는 '0'~'n+1-1'
    tmp[1] = false;                // 1은 소수가 아님.

    for (int i = 2; i * i <= n; i++)
    {
        if (tmp[i] == true)
        {
            for (int j = 2; i * j <= n; j++)
                tmp[i * j] = false;
        }
    }

    int primeCount = count(tmp.begin() + 1, tmp.end(), true); // 인덱스 0을 제외한, 1부터 끝까지 카운트.
    // 만약 소수가 아닌수를 구하고자한다면, count(tmp.begin()+1, tmp.end(), false);

    return primeCount;
}

int main(void) {
    cout << solution(10) << "\n";  // 1~10중 소수는 2,3,5,7 => 4개 출력

    return 0;
}