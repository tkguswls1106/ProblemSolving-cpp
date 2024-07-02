#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> s;
    char ch;
    int num;
    
    for(string str : operations) {
        stringstream ss(str);
        ss >> ch >> num;
        if(ch == 'I') {
            s.insert(num);
        }
        else {
            if(s.empty()) continue;
            if(num == 1) {
                s.erase(--s.end());
            }
            else {
                s.erase(s.begin());
            }
        }
    }
    
    if(s.empty()) return {0, 0};
    else return {*(--s.end()), *(s.begin())};
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}