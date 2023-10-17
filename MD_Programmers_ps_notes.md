# [프로그래머스 알고리즘 C++ 정리 노트 / ps(problem solving) 필기]

**코딩테스트 입문 100문제: https://school.programmers.co.kr/learn/challenges/beginner?order=acceptance_desc&languages=cpp**
```
#include <bits/stdc++.h>

using namespace std;

cout <<  // out이므로 밖을 가리키는 범위의 화살표로 외우면 편할듯?
cin >>  // in이므로 안을 가리키는 범위의 화살표로 외우면 편할듯?

ios::sync_with_stdio(0);
cin.tie(0);

---------------------------------------

< string >

string str(i, '*');  // i 개의 '*' 문자를 가진 str이라는 변수명의 문자열 생성
cout << str << "\n";

// 역순 정렬. 참고로 str은 스트링 변수명임.
// 참고로 vector 변수도 마찬가지로 똑같이 적용하면됨.
reverse(str.begin(), str.end());

string str = "TEST"; 일 때
str[0] 은 'T'를 반환. 
str.at(0) 은 'E'를 반환.
두 경우 모두 반환되는 문자는 char형임.

string answer = "";
answer += string(n,v);
// 이것처럼 char과는 다르게 string은 문자열을 +로 이을수있으며,
// push_back 메소드도 적용이 가능하다.

str1.append(str2);  // str 문자열 맨 뒤에 str2 문자열을 추가함.

string str_a ="7";
string str_b ="7.02";
string str_c ="3.14";
string str_d = "2300000000";
int after_a = stoi(str_a);  // "7"을 int형 7로 바꿔줌.
double after_b = stod(str_b);  // "7.02"를 double형 7.02로 바꿔줌.
float after_c = stof(str_c);  // "3.14"를 float형 3.14로 바꿔줌.
long int after_d = stof(str_d);  // "2300000000"을 long int형으로 바꿔줌.

// str1에서 문자열 str2를 찾고, 이것의 str1에서의 시작점 인덱스를 반환함. 존재하지않으면 -1을 반환받음.
string str1 = "TEST";
string str2 = "ST";
str1.find(str2);  // 2 반환함. (TEST에서 ST의 S는 2번째 인덱스므로)

string str2 = str1.substr(2);  // index 2의 위치부터 ~ 끝까지의 문자를 반환함.
string str2 = str1.substr(2,3);  // index 2의 위치부터 3개의 문자를 반환함.

str.insert(2,"bbb");  // index가 2인 위치에 있는 문자 앞에 삽입함.

str.replace(2,3,"bbb");  // index가 2인 위치에 있는 문자부터 ~ 3개의 문자를 "bbb"로 대체함.

str.erase(1,4);  // index 1~4인 부분을 부분적으로 지움.
str.erase(str.begin() + 2);  // 3인덱스의 문자를 제거함.
str.erase(find(str.begin(), str.end(), 'k'));  // str에서 k문자를 제거한다. 참고로 문자열이 아닌 문자 제거이다. 그리고 참고로 str.find()가 아닌 find()이다.

// remove 및 erase 해석 및 설명
my_string.erase(remove(my_string.begin(),my_string.end(),str[0]), my_string.end());
// remove(my_string.begin(), my_string.end(), str[0]): 이 함수는 my_string의 시작부터 끝까지 탐색하면서 str[0]과 일치하는 모든 문자를 "제거"한다. 그런데 여기에서 "제거"는 실제로 해당 요소들을 문자열에서 삭제하는 것이 아니라, 문자열의 뒷부분으로 이동시키는 것을 의미한다. remove는 이동이 끝난 후의 마지막 위치의 반복자를 반환한다.
// my_string.erase(...): remove에서 반환된 반복자를 사용하여 my_string에서 해당 위치부터 끝까지의 모든 문자를 "실제로 삭제"한다. 예를 들어, solution("apple", "pp")를 호출하면, str[0]은 'p'이다. 따라서 "apple"에서 'p' 문자를 모두 제거하면 결과는 "ale"가 된다.
이해를 돕기 위해 단계별로 예를 들어 설명해보자면,
원래 문자열: "apple"
remove 후의 문자열: "alepp" ('p'가 끝으로 이동되었다.)
remove가 반환한 반복자 위치: "ale|pp"
erase를 사용하여 "pp"를 삭제한 후의 문자열: "ale" 따라서 함수의 결과는 "ale"이다.

---------------------------------------

< vector >

vector 도 배열 안의 요소를 복사해서 넣어주는 방식을 사용하므로 지역변수처럼 값이 다시 원래대로 돌아와, 참조를 활용해야한다.

vector 배열을 초기화 시켜주지않았다면, 배열의 인덱스에 직접 접근해서 값을 할당하는건 불가능하다. 이러한 경우에는 push_back으로 넣어주어야한다.

vector 배열을 초기화 시켜줬다면, 배열의 인덱스에 직접 접근해서 값을 할당하는것도 가능하다.

벡터또한 인덱스가 0부터 시작이며, v.begin()+2 는 v[2]인 세번째 인덱스를 의미한다.

sort와 reverse함수를 사용하려면 #include <algorithm> 헤더를 작성해둬야한다.

- 벡터의 여러가지 초기화 방법 -
vector<int> v1;  // 아무것도 없는 비어있는 vector
vector<int> v2(5);  // 5개의 int형을 저장하는 vector(전부 0으로 초기화)
vector<int> v3(5,1);  // 5개의 int형을 저장하는 vector(전부 1로 초기화)
vector<int> v4 = { 1,2,3,4,5 };  // 배열과 같은 초기화
vector<int> v5(v4);  // v4의 벡터 요소를 복사해서 초기화

// 역순 정렬. 참고로 v는 벡터 변수명임.
// 참고로 string 변수도 마찬가지로 똑같이 적용하면됨.
reverse(v.begin(), v.end());

// 오름차순 정렬. 참고로 v는 벡터 변수명임.
sort(v.begin(), v.end());
sort(v.begin(), v.end(), less<int>());

// 내림차순 정렬
sort(v.rbegin(), v.rend());	
sort(v.begin(), v.end(), greater<int>());

// 자동 형식 추론 (auto), &는 참조.
vector<int> solution(vector<int> numbers) {
    for(auto& num : numbers)
    {
        num *=2;
    }

    return numbers;
}

// 위와 반면 밑은 새로운 벡터배열을 만들어 그안에 넣어주는 방식을 사용하고있으므로, auto& 처럼 참조를 사용하지 않아도 된다.
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(auto num : numbers) answer.push_back(2 * num);
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

map으로 반복문을 사용할때는 반복문 소괄호 매개변수 안에 각 인덱스로 map[i]를 접근하는 방법이 아닌, iterator로 요소에 접근해야한다. 반면 vector은 반복문에서 각 인덱스로도 접근이 가능하다.

---------------------------------------

< map >

map은 각 노드가 key와 value 쌍으로 이루어진 트리이다. 특히, 중복을 허용하지 않는다.
map은 key를 기준으로 정렬하며 오름차순으로 정렬한다.
#include <map>
map <key, value> map1;
- 오름차순 기본형태: map <int, int> map1;
- 내림차순 형태 예시1: map <int, int, greater> map1;
- 내림차순 형태 예시2: 데이터에 -(마이너스)를 붙여 삽입하여 처리하면 내림차순으로 정렬된다.

map 순회는 vector나 array랑 다르게 index가 아닌 iterator를 사용한다.
그래도 map은 insert없이 m[i] = "값" 으로만 적어도 없는지 확인하고 없으면 삽입한다.
위의 방법으로 조회와 수정도 가능하다.
단, vector iterator 처럼 iter[3] 같이 map이 아닌 iterator로는 임의접근 안된다. iter[3]은 안되고 map[3]은 가능하단 뜻이다.

map의 원소는 pair 객체로 저장되며,
pair 객체의 first 멤버 변수는 key로 second 멤버 변수는 value이다.
for (iter = m.begin(); iter != m.end(); iter++) { } 에서
key는 iter->first, value는 iter->second 이다. 아마도 iter.first 이런식으로도 가능한듯하다.

사용자가 map객체에 주어진 값의 쌍이 있는지 확인해야하는 경우 멤버 함수 count를 사용할 수 있다.
map에 키가 있으면 맵 컨테이너의 모든 키가 고유하므로 개수는 정확히 1이 된다. 반면에 키를 찾을 수 없으면 count 함수는 0을 반환한다.
    if (m.count(key)) {
        cout << "Key Exists!" << endl;
    } else {
        cout << "Key does not exist!" << endl;
    }

map으로 반복문을 사용할때는 반복문 소괄호 매개변수 안에 각 인덱스로 map[i]를 접근하는 방법이 아닌, iterator로 요소에 접근해야한다. 반면 vector은 반복문에서 각 인덱스로도 접근이 가능하다.

-------------

< map vs unordered_map >

- map:
#include <map>
map <int, int> map1;
pair<const Key, T> 로 이루어진 컨테이너임.
Key값 기준으로 기본적으로 오름차순 sorting 되어있음.
균형 이진탐색트리중에서 레드블랙트리로 구현되면서 sorting하므로 unordered_map보다 value값을 찾는 데에 오래걸릴 수 있음.
데이터가 N개일때 탐색속도는 O(logN)임.
map은 데이터 양이 보다 적을때와 Key를 이용하여 정렬을 해야할때 권장한다.

- unordered_map:
#include <unordered_map>
unordered_map <int, int> map1;
map과는 달리 Key 혹은 Value 기준으로 sorting 되어있지 않은 컨테이너임.
hash table 기반 hash container임. (Average: O(1)) 우리가 흔히 사용하는 hash 자료구조에 해당된다고 보면 됨.
Key값으로 hash value를 찾는 데에 시간이 적게 걸림.
데이터가 N개일때 탐색속도는 O(1)임.

map은 데이터 양이 보다 적을때와 Key를 이용하여 정렬을 해야할때 권장한다.
unordered_map은 대량의 데이터를 저장할때와 정렬이 필요없을때 권장한다.
즉, 정렬이 필요 없을 경우에는 map보다는 unordered_map을 사용하는 것이 훨씬 성능이 좋다.

---------------------------------------

배열(벡터)의 요소의 합을 구하는 함수 accumulate
#include <numeric.h>
accumulate(시작, 끝, 하나씩 더할 값의 초깃값);
int sum = accumulate(v.begin(), v.end(), 0);
double sum = accumulate(v.begin(), v.end(), 0.0);

---------------------------------------

```