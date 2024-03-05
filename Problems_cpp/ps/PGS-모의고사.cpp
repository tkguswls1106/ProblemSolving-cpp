#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> v;
    v.push_back({1, 2, 3, 4, 5});
    v.push_back({2, 1, 2, 3, 2, 4, 2, 5});
    v.push_back({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    
    int size1=5, size2=8, size3=10;
    int cnt1=0, cnt2=0, cnt3=0;
    for(int i=0; i<answers.size(); i++) {
        if(v[0][i%size1] == answers[i]) cnt1++;
        if(v[1][i%size2] == answers[i]) cnt2++;
        if(v[2][i%size3] == answers[i]) cnt3++;
    }
    
    int maxValue = max({cnt1, cnt2, cnt3});
    if(maxValue == cnt1) answer.push_back(1);
    if(maxValue == cnt2) answer.push_back(2);
    if(maxValue == cnt3) answer.push_back(3);
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}