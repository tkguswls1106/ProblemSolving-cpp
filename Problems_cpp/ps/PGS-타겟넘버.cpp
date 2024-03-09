#include <vector>

using namespace std;

// 최대 2^20 = (2^10)^2 = 1024^2 = 1000000 조금 넘는 숫자의 연산 횟수
// => 1억번 안넘으므로, dfs재귀로 가능.

int t;
int cnt = 0;
void dfs(int x, int sum, vector<int>& numbers) {  // x는 연산한 개수
    if(x == numbers.size()) {
        if(sum == t) cnt++;
        return;
    }
    
    dfs(x+1, sum+numbers[x], numbers);
    dfs(x+1, sum-numbers[x], numbers);
}

int solution(vector<int> numbers, int target) {
    t = target;
    dfs(0, 0, numbers);
    
    return cnt;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}