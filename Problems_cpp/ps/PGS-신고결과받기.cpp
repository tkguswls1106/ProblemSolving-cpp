#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    unordered_map<string, vector<string>> vM;
    unordered_map<string, int> cntM;
    
    string a,b;
    for(string str : report) {
        stringstream ss(str);
        ss >> a >> b;
        
        vM[a].push_back(b);
        cntM[b]++;
    }
    
    vector<int> answer;
    for(string str : id_list) {
        int cnt = 0;
        for(string str2 : vM[str]) {
            if(cntM.count(str2) != 0 && cntM[str2] >= k) {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}