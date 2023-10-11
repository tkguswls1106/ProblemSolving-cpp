# [프로그래머스 알고리즘 C++ 정리 노트 / ps(problem solving) 필기]

**코딩테스트 입문 100문제: https://school.programmers.co.kr/learn/challenges/beginner?order=acceptance_desc&languages=cpp**
```
#include <bits/stdc++.h>

cout <<  // out이므로 밖을 가리키는 범위의 화살표로 외우면 편할듯?
cin >>  // in이므로 안을 가리키는 범위의 화살표로 외우면 편할듯?

vector 도 배열 안의 요소를 복사해서 넣어주는 방식을 사용하므로 지역변수처럼 값이 다시 원래대로 돌아와, 참조를 활용해야한다.

vector 배열을 초기화 시켜주지않았다면, 배열의 인덱스에 직접 접근해서 값을 할당하는건 불가능하다. 이러한 경우에는 push_back으로 넣어주어야한다.

vector 배열을 초기화 시켜줬다면, 배열의 인덱스에 직접 접근해서 값을 할당하는것도 가능하다.

// 자동 형식 추론 (auto), &는 참조.
vector<int> solution(vector<int> numbers) {
    for(auto& v : numbers)
    {
        v *=2;
    }

    return numbers;
}

// 위와 반면 밑은 새로운 벡터배열을 만들어 그안에 넣어주는 방식을 사용하고있으므로, auto& 처럼 참조를 사용하지 않아도 된다.
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(auto a : numbers) answer.push_back(2 * a);
    return answer;
}

```