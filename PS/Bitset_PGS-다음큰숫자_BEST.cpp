#include <bitset>

using namespace std;

int solution(int n) {
    bitset<32> bs(n);  // 2^28 = 1억 이상이긴하지만, 32가 보다 표준 정수형으로 쓰임.
    int cnt = bs.count();  // 비트셋에서 1의 개수
    
    while(true) {
        bitset<32> bs2(++n);
        if(bs2.count() == cnt) return n;
    }
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}