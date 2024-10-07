#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// - bitset count() 개념 참고 :
// 이 문제에는 해당되지 않지만, 참고로 bitset 내에서 1의 숫자를 구하고싶다면 bs.count()를 사용하면 된다.

// bitset말고 시프트연산자를 활용해서 풀어도되는 문제이기도 하다.
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0; i<n; i++) {
        int num = (arr1[i] | arr2[i]);  // 10진수
        bitset<17> bs(num);  // 2진수 (bitset은 bitset<n> 이렇게 변수로 크기할당해서 선언이 불가능하다.)
        
        // 참고로 bitset에서의 to_string()은,
        // 'int num = 3; string str = to_string(num);' 처럼
        // 평소에쓰던 to_string(변수) 과는 다른 메소드 방식이다.
        string str1 = bs.to_string();  // bitset에서는 to_string(bs); 이렇게쓰면 틀린다.
        string str2 = str1.substr(17-n);
        
        for(char& ch : str2) {
            ch = ch == '1' ? '#' : ' ';
        }
        answer.push_back(str2);
    }
    
    return answer;
}

int main()
{
    int n = 5;
    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };

    vector<string> answer = solution(n, arr1, arr2);

    for(string str : answer) cout << str << "\n";  // => 출력 예시는 밑에.
    // #####
    // # # #
    // ### #
    // #  ##
    // #####


    return 0;
}