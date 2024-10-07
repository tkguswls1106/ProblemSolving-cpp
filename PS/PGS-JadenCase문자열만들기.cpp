#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;

// - 이 방식 말고 다른풀이 : s[i-1] 값이 ' '이라면 현재 s[i]값이 단어의 첫문자임을 이용하여 풀어도 됨.

void convertStr(string& str) {
    if(!isdigit(str[0])) str[0] = toupper(str[0]);
    if(str.size() >= 2) {
        for(int i=1; i<str.size(); i++) {
            str[i] = tolower(str[i]);
        }
    }
}

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    string str;
    while(ss >> str) {
        convertStr(str);
        answer += str;
    }
    
    // 공백문자가 연속해서 나올 수 있으므로
    auto iter = find(s.begin(), s.end(), ' ');
    while(iter != s.end()) {
        int idx = iter - s.begin();
        answer.insert(idx, " ");
        iter = find(iter+1, s.end(), ' ');
    }
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}