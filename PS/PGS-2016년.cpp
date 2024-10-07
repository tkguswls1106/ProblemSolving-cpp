#include <string>
#include <vector>

using namespace std;

// - 평년: 2월이 28일까지 존재하는 년도.
// - 윤년: 2월이 29일까지 존재하는 년도.
// => 문제에서 2016년이 윤년이라 명시되어있음.

string solution(int a, int b) {
    vector<int> cntV = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int sum = 0;
    for(int i=1; i<a; i++) {
        sum += cntV[i];
    }
    sum += b;
    
    vector<string> dayV = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    string answer = dayV[sum % 7];
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}