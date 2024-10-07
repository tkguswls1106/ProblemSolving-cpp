#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,double>& a, pair<int,double>& b) {
    if(a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    
    vector<int> userV;
    userV.resize(N+2);  // idx = 0 ~ N+1
    int man = stages.size();
    
    for(int stage : stages) {
        userV[stage]++;
    }
    
    vector<pair<int,double>> v;  // {스테이지번호, 실패율}
    for(int i=1; i<=N; i++) {
        int cnt = userV[i];
        double fail;
        
        if(man == 0) fail = 0.0;  // 분모를 0으로하여 나누지않도록 주의. (심지어 '스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다'라고 문제에 명시되어있음.)
        else fail = double(cnt) / double(man);
        
        v.push_back({i, fail});
        man -= cnt;
    }
    
    sort(v.begin(), v.end(), compare);
    vector<int> answerV;
    for(auto p : v) answerV.push_back(p.first);
    
    return answerV;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}