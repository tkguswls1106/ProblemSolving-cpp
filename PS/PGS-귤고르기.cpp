#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int,int> m;
    for(int num : tangerine) m[num]++;
    
    vector<pair<int,int>> v;
    for(auto p : m) v.push_back({p.second, p.first});
    sort(v.rbegin(), v.rend());
    
    int cnt = 0;
    for(auto p : v) {
        cnt++;
        k -= p.first;
        if(!(k>0)) return cnt;
    }
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}