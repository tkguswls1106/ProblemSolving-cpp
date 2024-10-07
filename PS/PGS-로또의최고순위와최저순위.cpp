#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    set<int> s;
    for(int n : win_nums) s.insert(n);
    
    int cnt0 = 0, cntCorrect = 0;
    for(int n : lottos) {
        if(n == 0) cnt0++;
        else {
            if(s.count(n) > 0) {
                cntCorrect++;
                s.erase(n);
            }
        }
    }
    
    int maxCorrect = (cnt0 < s.size() ? cnt0 : s.size()) + cntCorrect;
    int minCorrect = cntCorrect;
    
    if(maxCorrect < 2) answer.push_back(6);
    else answer.push_back(7 - maxCorrect);
    if(minCorrect < 2) answer.push_back(6);
    else answer.push_back(7 - minCorrect);
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}