#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    unordered_map<string, int> m1;
    unordered_map<int, string> m2;
    unordered_map<string, int> gift_countM;
    unordered_map<string, int> resultM;
    
    int size = friends.size();
    for(int i=0; i<size; i++) {
        m1[friends[i]] = i;
        m2[i] = friends[i];
    }
    
    vector<vector<int>> v;
    v.resize(size, vector<int>(size));
    
    for(string allstr : gifts) {
        stringstream ss(allstr);
        string str1, str2;
        ss >> str1;
        ss >> str2;
        int idx1 = m1[str1], idx2 = m1[str2];
        v[idx1][idx2]++;
        gift_countM[str1]++;
        gift_countM[str2]--;
    }
    
    int jPlus = 1;
    for(int i=0; i<size; i++) {
        for(int j=jPlus; j<size; j++) {
            if(i==j) break;
            
            if(v[i][j] > v[j][i]) resultM[m2[i]]++;
            else if(v[i][j] < v[j][i]) resultM[m2[j]]++;
            else {  // 같으면
                if(gift_countM[m2[i]] > gift_countM[m2[j]]) resultM[m2[i]]++;
                else if(gift_countM[m2[i]] < gift_countM[m2[j]]) resultM[m2[j]]++;
                // else 로 이것도 같으면 선물을 주고받지 않음.
            }
        }
        jPlus++;
    }
    
    int maxValue = 0;  // 이 문제의 경우에, 혹시나 -1로 초기값 세팅하지 말것.
    for(auto iter=resultM.begin(); iter!=resultM.end(); iter++){
        maxValue = max(maxValue, (*iter).second);
    }
    
    return maxValue;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}