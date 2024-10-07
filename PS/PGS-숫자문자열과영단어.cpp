#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

int solution(string s) {
    string answerStr = "";
    unordered_map<string, char> m = { {"zero",'0'}, {"one",'1'}, {"two",'2'}, {"three",'3'}, {"four",'4'}, {"five",'5'}, {"six",'6'}, {"seven",'7'}, {"eight",'8'}, {"nine",'9'}};
    
    string str = "";
    for(char ch : s) {
        if(!isdigit(ch)) {
            str += ch;
            if(m.count(str) > 0) {
                answerStr += m[str];
                str = "";
            }
        }
        else {
            answerStr += ch;
            str = "";
        }
    }
    
    int answer = stoi(answerStr);
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}