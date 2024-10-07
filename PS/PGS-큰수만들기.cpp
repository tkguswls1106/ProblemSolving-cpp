#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> v;
    for(char ch : number) v.push_back(ch - '0');
    int len = number.size() - k;  // 남겨야 할 숫자의 개수
    
    while(k > 0 && answer.size() < len) {
        int maxIdx = max_element(v.begin(), v.begin()+k+1) - v.begin();  // = 가장 큰수 포함 앞의 숫자개수
        answer += (v[maxIdx] + '0');
        v.erase(v.begin(), v.begin()+maxIdx+1);
        k -= maxIdx;
    }

    for(int num : v) {
        if(answer.size() < len) {  // 필요한 숫자 개수만큼만 더 추가
            answer += (num + '0');
        }
    }
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}