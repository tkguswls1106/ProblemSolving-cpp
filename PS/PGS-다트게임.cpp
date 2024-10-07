#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int prev = 0;
    for(int i=0; i<dartResult.size(); i++) {
        char ch = dartResult[i];
        
        int num;
        if(0 <= i-2 && dartResult[i-2] == '1' && dartResult[i-1] == '0') num = 10;
        else if (isdigit(dartResult[i-1])) num = dartResult[i-1]-'0';
        
        if(ch == 'S' || ch == 'D' || ch == 'T') {
            if(ch=='D') num = pow(num,2);
            else if(ch=='T') num = pow(num,3);
            
            if(i+1 < dartResult.size()) {
                if(dartResult[i+1] == '*') {
                    num *= 2;
                    if(i+1 != 2) prev *= 2;
                }
                else if(dartResult[i+1] == '#') num *= -1;
            }
        }
        else {
            continue;
        }
        
        answer += prev;
        prev = num;
    }
    answer += prev;
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}