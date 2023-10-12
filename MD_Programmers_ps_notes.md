# [프로그래머스 알고리즘 C++ 정리 노트 / ps(problem solving) 필기]

**코딩테스트 입문 100문제: https://school.programmers.co.kr/learn/challenges/beginner?order=acceptance_desc&languages=cpp**
```
#include <bits/stdc++.h>

cout <<  // out이므로 밖을 가리키는 범위의 화살표로 외우면 편할듯?
cin >>  // in이므로 안을 가리키는 범위의 화살표로 외우면 편할듯?

vector 도 배열 안의 요소를 복사해서 넣어주는 방식을 사용하므로 지역변수처럼 값이 다시 원래대로 돌아와, 참조를 활용해야한다.

vector 배열을 초기화 시켜주지않았다면, 배열의 인덱스에 직접 접근해서 값을 할당하는건 불가능하다. 이러한 경우에는 push_back으로 넣어주어야한다.

vector 배열을 초기화 시켜줬다면, 배열의 인덱스에 직접 접근해서 값을 할당하는것도 가능하다.

벡터또한 인덱스가 0부터 시작이며, v.begin()+2 는 v[2]인 세번째 인덱스를 의미한다.

// 오름차순 정렬. 참고로 v는 벡터 변수명임.
sort(v.begin(), v.end());
sort(v.begin(), v.end(), less<int>());

// 내림차순 정렬
sort(v.rbegin(), v.rend());	
sort(v.begin(), v.end(), greater<int>());

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

// 벡터 배열 max 값 구하는법
int max = *max_element(v.begin(), v.end());
// 그 이유는 begin과 end는 요소의 값을 반환하는게 아닌 요소를 가리키는것 뿐이기때문인데, 그렇기에 *포인터를 붙여서 벡터에서 최댓값을 가리키는 반복자가 가리키는 값을 반환하는 것이다.
// 만약 *포인터를 뺐다면 최댓값을 가리키는 반복자를 반환하는 것이기에 에러가 난다.

// 백터 배열 max 인덱스 구하는법
int max_index = max_element(v.begin(), v.end()) - v.begin();
// 'max_element(v.begin(), v.end())' - 'v.begin()' 인것이다.
// 그 이유는 최댓값을 가리키는 반복자와 벡터의 시작 위치를 가리키는 반복자 간의 차를 계산함으로써, 최대 인덱스를 구하는 것이기 때문이다.

```