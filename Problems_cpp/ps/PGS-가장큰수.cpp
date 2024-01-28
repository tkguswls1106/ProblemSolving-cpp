#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// - compare 함수의 반환값이 true일 경우:
// 첫번째 인자가 두번째 인자보다 "작다"는 것을 의미함.
// 이 경우, 첫번째 인자가 두번째 인자보다 앞에 위치하도록 함.
// - compare 함수의 반환값이 false일 경우:
// 첫번째 인자가 두번째 인자보다 "크거나 같다"는 것을 의미함.
// 이 경우, 두번째 인자가 첫번째 인자보다 앞에 위치하도록 함.
// ==> 결론: 즉, true면 순서 그대로 유지하고, false면 둘의 순서를 뒤바꾼다.
// 즉, 순서가 원하는대로 오도록 false일경우 뒤바꿔서 재배치하겠다는 의미인것이다.

bool compare(int a, int b) {
    string str1 = to_string(a);
    string str2 = to_string(b);
    
    return str1+str2 > str2+str1;  // 리턴값이 false이면, b 다음 a가 오게 된다.
}

string solution(vector<int> numbers) {
    
    sort(numbers.begin(), numbers.end(), compare);
    
    string answer = "";
    for(int n : numbers) answer += to_string(n);
    
    // answer가 "00", "000" 같은것일경우를 방지하기위해 작성함.
    if(answer[0] == '0') answer = "0";
    
    return answer;
}

int main()
{
    vector<int> numbers1 = { 6, 10, 2 };
    vector<int> numbers2 = { 3, 30, 34, 5, 9 };

    string answer1 = solution(numbers1);
    string answer2 = solution(numbers2);

    cout << answer1 << "\n";  // => 6210 출력
    cout << answer2 << "\n";  // => 9534330 출력

    return 0;
}