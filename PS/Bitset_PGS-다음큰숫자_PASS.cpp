#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

bool isOne(char ch) {
    return ch == '1';
}

int getCnt(string& str) {  // 사실 이건 bs.count()로 대체 가능함.
    return count_if(str.begin(), str.end(), isOne);
}

int solution(int n) {
    bitset<28> bs(n);  // 2^28 = 1억 이상임.
    string bsStr = bs.to_string();
    int cnt = getCnt(bsStr);
    
    while(true) {
        bitset<28> bs2(++n);
        string bsStr2 = bs2.to_string();
        if(getCnt(bsStr2) == cnt) return n;
    }
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}