#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_multiset<string> s;
    for(string str : participant) {
        s.insert(str);
    }
    
    for(string str : completion) {
        s.erase(s.find(str));
    }

    return *s.begin();
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}