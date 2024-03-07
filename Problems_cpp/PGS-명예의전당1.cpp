#include <vector>
#include <algorithm>

using namespace std;

// 코딩 테스트에서 문제의 제한 시간은 보통 1~5초 정도이다.
// 일반적인 CPU 기반의 PC나 채점용 컴퓨터에서 1초에 실행할 수 있는 최대 연산 횟수는 약 1억번이다.

// STL의 sort함수는 퀵소트로써, 최악의경우 n^2의 시간복잡도를 가진다.
// k가 최대 100일때 퀵소트의 최악 시간복잡도 = 10000
// score의 길이가 최대 1000일때 최악 시간복잡도 결론 = 10000 * 1000 = 10000000 번의 연산 (이는 1억번 미만임.)
// => 감당 가능 => sort 사용해도 무리없이 정답.

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    vector<int> v;
    for(int i=0; i<score.size(); i++) {
        v.push_back(score[i]);
        sort(v.rbegin(), v.rend());
        if(i < k)
            answer.push_back(v.back());
        else
            answer.push_back(v[k-1]);
    }
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}