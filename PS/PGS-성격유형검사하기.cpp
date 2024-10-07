#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char,int> m = {{'R',0},{'T',0},{'C',0},{'F',0},{'J',0},{'M',0},{'A',0},{'N',0}};

pair<char,int> funcP(string str, int choice) {
    char a = str[0], b = str[1];
    char resultCh = a;
    int resultNum = 0;
    
    if(choice <= 3) {
        resultNum = 4 - choice;
    }
    else if(5 <= choice) {
        resultCh = b;
        resultNum = choice - 4;
    }

    return make_pair(resultCh, resultNum);
}

char funcCh(char a, char b) {
    if(m[a] > m[b]) return a;
    else if(m[a] == m[b]) return a;
    else return b;
}

string solution(vector<string> survey, vector<int> choices) {
    
    for(int i=0; i<survey.size(); i++) {
        pair<char,int> p = funcP(survey[i], choices[i]);
        m[p.first] += p.second;
    }
    
    string answer = "";
    answer += funcCh('R', 'T');
    answer += funcCh('C', 'F');
    answer += funcCh('J', 'M');
    answer += funcCh('A', 'N');
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}