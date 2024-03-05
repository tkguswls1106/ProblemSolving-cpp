#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    while(true) {
        if(answer+1 <= d.size() && budget - d[answer] >= 0) {
            budget -= d[answer];
            answer++;
        }
        else break;
    }
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략

    return 0;
}