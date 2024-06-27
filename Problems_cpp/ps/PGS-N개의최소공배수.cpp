#include <vector>

using namespace std;

int gcd(int a, int b) {  // 최대공약수
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {  // 최소공배수
    return a*b / gcd(a,b);
}

int solution(vector<int> arr) {
    int a = arr[0];
    for(int i=1; i<arr.size(); i++) {
        int b = arr[i];
        a = lcm(a, b);
    }
    
    return a;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}