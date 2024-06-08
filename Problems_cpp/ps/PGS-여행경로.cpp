#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, multiset<string>> m;
vector<string> answer;
int ticketCnt = 0;
bool isFind = false;

void dfs(string start) {
    if(answer.size() == ticketCnt) {
        isFind = true;
        return;
    }
    
    for(auto iter = m[start].begin(); iter != m[start].end(); iter++) {
        string next = *iter;
        
        answer.push_back(next);
        m[start].erase(iter);
        dfs(next);  // 다음 목적지로 dfs 탐색
        
        if(isFind == true) return;  // 올바른 경로를 찾았다면 더 이상의 탐색 중단
        
        // 탐색에 실패했다면, 이전 상태로 백트래킹
        answer.pop_back();
        iter = m[start].insert(next);  // 삭제된 요소를 재삽입 후, iter++로 다음꺼부터 이어서 탐색 가능.
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketCnt = tickets.size() + 1;
    
    for(auto v : tickets) {
        m[v[0]].insert(v[1]);
    }
    
    answer.push_back("ICN");  // 처음 시작은 항상 ICN
    dfs("ICN");
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}