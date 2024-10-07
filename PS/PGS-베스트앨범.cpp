#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& p1, pair<int,int>& p2) {
    if(p1.first != p2.first) return p1.first > p2.first;  // 재생횟수 내림차순
    else return p1.second < p2.second;  // 고유번호 오름차순
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, vector<pair<int,int>>> genresM;  // <장르, <재생횟수,고유번호>>
    unordered_map<string, int> genresCntM;  // <장르, 재생횟수+>
    for(int i=0; i<genres.size(); i++) {
        string ge = genres[i];
        int pl = plays[i];
        genresM[ge].push_back({pl,i});
        genresCntM[ge] += pl;
    }
    
    set<pair<int,string>, greater<>> s;
    for(auto p : genresCntM) s.insert({p.second, p.first});
    
    for(auto iter=s.begin(); iter!=s.end(); iter++) {
        string ge = (*iter).second;
        vector<pair<int,int>> v = genresM[ge];
        sort(v.begin(), v.end(), cmp);
        
        for(int i=0; i<v.size() && i<2; i++) {  // 장르당 최대 2곡까지만 가능.
            answer.push_back(v[i].second);
        }
    }

    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}