#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, int> m;
    for(int i=0; i<clothes.size(); i++) {
        m[clothes[i][1]]++;
    }
    
    int answer = 1;
    for(auto p : m) {
        int cnt = p.second;
        cnt++;  // +1은 안입을경우
        answer *= cnt;
    }
    answer--;  // 전부 안입은경우는 경우에서 제외시켜야한다.
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}