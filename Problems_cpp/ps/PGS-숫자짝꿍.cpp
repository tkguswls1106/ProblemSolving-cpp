#include <string>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<int,int,greater<int>> m;
    sort(Y.rbegin(), Y.rend());
    
    for(char ch : X) {
        int num = ch - '0';
        m[num]++;
    }
    
    for(char ch : Y) {
        int num = ch - '0';
        if(m.count(num) > 0 && m[num] >= 1) {
            answer += (num + '0');
            m[num]--;
        }
    }
    
    if(answer == "")  // 짝꿍이 존재하지않을 경우
        return "-1";
    else if(answer[0] == '0')  // "00" 같은값 방지 (참고로, 'stoi(answer) == 0' 이걸로 풀면 범위초과됨.)
        return "0";
    else
        return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}