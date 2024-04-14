#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int todayDay = year * 12 * 28 + (month-1) * 28 + day;  // 첫번째 년도도 1월부터 시작하므로, month-1을 해주어야한다.
    
    unordered_map<char, int> m;
    char ch; int num;
    for(string str : terms) {
        stringstream ss(str);
        ss >> ch >> num;
        m[ch] = num;
    }
    
    int number = 1;
    string date;
    for(string str : privacies) {
        stringstream ss(str);
        ss >> date >> ch;
        
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
        int priDay = year * 12 * 28 + (month-1) * 28 + day;  // 첫번째 년도도 1월부터 시작하므로, month-1을 해주어야한다.
        
        if(priDay + m[ch]*28 <= todayDay) answer.push_back(number);
        number++;
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}