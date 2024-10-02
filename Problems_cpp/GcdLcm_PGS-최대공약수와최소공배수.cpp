#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {  // 최대공약수
    if(b == 0) return a;  // 헷갈릴때 Tip: b비 a아
    return gcd(b, a%b);  // 헷갈릴때 Tip: b비 a%b압
}

int lcm(int a, int b) {  // 최소공배수
    return a*b / gcd(a,b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n,m));
    
    return answer;
}

int main()
{
    vector<int> answer1 = solution(3, 12);
    vector<int> answer2 = solution(2, 5);

    for(int num : answer1) cout << num << " ";  // => 3 12 출력
    cout << "\n";
    for(int num : answer2) cout << num << " ";  // => 1 10 출력
    cout << "\n";


    return 0;
}