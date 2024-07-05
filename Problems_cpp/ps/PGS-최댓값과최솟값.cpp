#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

string solution(string s) {
    priority_queue<int, vector<int>, greater<int>> pq1;  // 최소힙
    priority_queue<int> pq2;  // 최대힙
    
    stringstream ss(s);
    int num;
    while(ss >> num) {
        pq1.push(num);
        pq2.push(num);
    }
    
    string answer = to_string(pq1.top()) + " " + to_string(pq2.top());
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}