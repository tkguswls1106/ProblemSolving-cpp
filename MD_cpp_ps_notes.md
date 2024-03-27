# [알고리즘 C++ 정리 노트 / ps(problem solving) 필기]

**- PS process:&nbsp;&nbsp;프로그래머스 입문 100문제 -> 프로그래머스 Lv.1 -> 바킹독 -> 백준**
```
#include <bits/stdc++.h>

using namespace std;

cout <<  // out이므로 밖을 가리키는 범위의 화살표로 외우면 편할듯?
cin >>  // in이므로 안을 가리키는 범위의 화살표로 외우면 편할듯?

cout << num << endl; 말고
cout << num << '\n';

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

'0'의 ASCII 값은 숫자 0의 정수 표현이다. ASCII 값으로는 48이다.
'9'의 ASCII 값은 숫자 0의 정수 표현이다. ASCII 값으로는 48+9=57이다.
'A'의 ASCII 값은 알파벳 'A'의 정수 표현이다. ASCII 값으로는 65이다.
'a'의 ASCII 값은 알파벳 'a'의 정수 표현이다. ASCII 값으로는 97이다.
알파벳은 총 26개이다.

C++ 스타일의 형변환 방법은
int(4.0)
static_cast<int>(4.0)

'return a = b;' 라는 코드의 의미는, a에 b값을 할당하고 바로 그 a를 반환해주는 것이다.
즉, b를 할당한 이후의 a값을 반환해준다.

반복자가 두가지 들어가는 함수인 함수명(반복자1, 반복자2); 이런것은 위치가 "반복자1" ~ "'반복자2'-1" 를 의미한다.
절대로 "반복자1" ~ "반복자2" 위치라고 잘못 헷갈리지 말자.
// 예를들어
v.erase(반복자1, 반복자2);  // "반복자1" ~ "'반복자2'-1" 위치 범위의 요소 삭제.
fill(반복자1, 반복자2, 채울값);  // "반복자1" ~ "'반복자2'-1" 위치 범위에 채울값 대체.

for문에서 파라미터값으로 증감식 생략을 할 수 있고, 생략하게되면 무한루프에 빠지게된다. 대신 ;는 써주어야한다.
그래서 위를 응용하자면, 생략후 for문 안에서 if~else문을 이용해서 증감식을 따로 작성해줄수도 있다.

// for문 사용가능 다른 예시
for(string eng : {"aya", "ye", "woo", "ma"}) { }

// C++에서는 int arr[4] 같은 일반array에도 밑의 for문 방식을 적용할 수 있다.
int arr[4] = {1,2,3,4};
for(int n : arr) { cout << n << " "; }

// int to char 방법
int zeroNum = 0;
int fiveNum = 5;
char ch1 = zeroNum + '0';  // ch1 은 문자'0'
char ch2 = fiveNum + '0';  // ch2 은 문자'5'

// char to int 방법
char zeroCh = '0';
char fiveCh = '5';
int num1 = zeroCh - '0';  // num1 은 숫자0
int num2 = fiveCh - '0';  // num2 은 숫자5

// 시프트 연산자
3 << 4  // 3*2*2*2*2 = 3 * 2^4 = 48
13 >> 3 // 13/(2*2*2) = 13/(2^3) = 1

bool의 기본 초기값은 false 이다.

// 조건과 증감 동시사용 예시
    for(const auto v : array)
        answer += (v > height);

// 배열이 빈경우 -1을 하나 채워 반환하는법 예시
if(arr.empty()) {
    return vector<int>(1, -1);  // return { -1 }; 도 가능함.
}

전역변수로 선언한 int나 int 배열array은 따로 초기화를 안하면 0이 채워진다.

특정 범위내의 소수를 판별할때에는 '에라토스테네스의 체' 알고리즘을 사용하는것이 좋다. 관련 자세한 설명은 PrimeNumber-Eratos.cpp 파일에 작성해두었다.

스택과 큐는 별도의 재초기화 clear 함수가 존재하지 않는다. 그래서 밑의 방법을 사용하면된다. (st는 스택 변수명, qu는 큐 변수명으로 가정하겠다.)
while(!st.empty()) st.pop();  // 스택 비우기 clear
while(!qu.empty()) qu.pop();  // 큐 비우기 clear

보통 3차원 배열을 순회할때는 for문 변수 순서가 높이z,행x,열y가 된다. 순서를 주의하자.
2차원은 평소처럼 행x,열y 순서로 해주면 된다.

BFS에서는 큐를 활용하지만, DFS에서는 스택을 활용한다.
그 이유는 스택에서는 last-in first-out 이므로, 최근에 넣은걸 위에서 바로 빼므로,
최근 좌표의 주변으로 계속 타고타고 들어가서 깊이 우선 탐색이 되기 때문이다. 그래서 DFS에서는 스택을 사용하는 것이다.

BFS는 너비우선탐색이기에 '인접한 칸은 현재의 칸보다 거리가 1만큼 떨어져있다.'라는 내용이 성립하지만,
DFS는 깊이우선탐색이기에 그렇지 않다는 점을 주의해야한다.
그러므로, 거리측정을 할 문제의 경우에는 BFS가 더 적합한 알고리즘이다.
웬만하면 다차원 배열 순회하는 문제를 풀때는 DFS보단 BFS를 적극적으로 활용하는것이 좋다.
DFS는 나중에 그래프와 트리 자료구조에서 유용하게 쓰일것이다.

백트래킹의 dfs에서만 "'push & visited=1 & dfs호출' 이후 'pop & visited=0'" 이러한 과정을 거치기때문에,
백트래킹이 아닌 일반적인 dfs를 사용하는 문제의 경우에는, 어차피 백트래킹처럼 pop으로 되돌아가질 않기때문에, 차후 pop이나 visited=0 의 과정은 작성하지 말아야한다.

트리란 자료구조의 일종이며, '사이클이 없이' '모든 정점이 연결'되어있는 무방향의 '그래프'이다.
모든 정점이 연결되어있지만 사이클이 없기에, 정점의 개수가 V개이면 간선의 개수는 V-1개이다.
사이클이 존재하지 않으므로, 한 정점에서 다른 정점으로 갈 수 있는 방법(경로로써의 경우의 수)은 단 1가지뿐이다.
기본적으로 트리는 그래프의 특별한 한 종류이기 때문에, BFS 및 DFS 알고리즘을 적용시킬 수 있다.

삼각형 관련 알고리즘을 풀때에, 삼각형이 되기위한 조건인 '가장 큰 변의 길이 < 나머지 두 변의 길이 합'임을 명심하고 풀자.

피보나치 수열은 N이 커질수록 값이 급속도로 증가하므로 DP 배열의 자료형을 long long으로 사용해야한다.

lower_bound와 upper_bound는 이분탐색(Binary Search)을 기반으로 탐색하는 함수이므로, 시간복잡도는 O(logN)이다.
이분탐색 알고리즘인 밑의 STL 함수들은 반드시 해당 배열을 오름차순으로 정렬 후에 적용해야만 한다.
- binary_search(v.begin(), v.end(), num);  // 검색하여 찾는 값이 존재하면 true, 아니면 false를 반환함.
- lower_bound(v.begin(), v.end(), num);  // 찾고자 하는 값 이상이 처음 나타나는 위치의 iter반복자를 반환함.
- upper_bound(v.begin(), v.end(), num);  // 찾고자 하는 값의 다음(초과) 값이 최초로 나타나는 위치의 iter반복자를 반환함.
참고로 벡터가 아닌 일반배열이라면, 인덱스 구할때 lower_bound(arr, arr + 6, 3) - arr; 뭐 이런식으로도 사용 가능하다.

-------------

[ 자료형에 따른 find 종류 및 반환값 설명 ]

- 순차 컨테이너: 데이터 요소를 선형으로 저장하며 순서대로 접근할 수 있는 컨테이너이다.
=> 배열, 벡터, 리스트, 덱(Deque)
- 연관 컨테이너: 데이터 요소와 연관된 다른 데이터(키)를 사용하여 저장하며, 키를 통해 데이터를 검색하거나 정렬할 수 있다.
=> 맵(Map), 셋(Set)
// 연관 컨테이너에서는 find()함수를 사용할때, find() 단독사용말고 map.find()처럼만 사용해야한다. str.find()는 인덱스를 반환하는반면, find() 반환값처럼 map.find()도 반복자를 반환한다.
// 연관 컨테이너는 순차 컨테이너와는 다르게, 아마도 iter++;로 사용해야지 begin()+1 이렇게는 안되는듯 하다.

< string 에서의 find >
string str = "TEST";
str.find("ST");  // 인덱스 반환 (만약 일치하는 값이 없다면, string::npos(== 쓰레기 값)인 4294967295 처럼 반환함. 근데 듣기론 -1도 될지도모르겠다. 참고로 아마 auto 자료형으로도 일단 선언 가능.)
str.find("S");  // 인덱스 반환
auto findIdx = s.find("ST", idx);  // idx인덱스부터 끝까지 검색함. 찾은 인덱스 혹은 string::npos 를 반환한다.
find(str.begin(), str.end(), 'S');  // 반복자 반환 (참고로 이방식은 문자열 검색은 안된다. 문자 검색만 가능하다.)

< vector 에서의 find >
vector<int> v = {10, 20, 30, 40, 50};
find(v.begin(), v.end(), 30);  // 반복자 반환 (만약 범위 내에 찾고자 하는 값이 없다면, 반복자 end를 반환함.)

< map 에서의 find >
map<string,int> m = {
        {"ab", 10},{"cd", 20},{"ef", 30}
};
string key = "cd";
m.find(key);  // 반복자 반환 (인덱스 반환 아니니까 주의하기!)

< set 에서의 find >
int key = 10;
s.find(key);  // 반복자 반환 (인덱스 반환 아니니까 주의하기!)

-------------

[ 자료형에 따른 erase 파라미터값 ]

< string 에서의 erase >
str.erase(인덱스);  // 인덱스부터 전부 삭제.
str.erase(인덱스, 개수);  // 인덱스부터 개수만큼 삭제.
str.erase(반복자);  // 해당 반복자 위치의 요소만 삭제.
str.erase(반복자1, 반복자2);  // "반복자1" ~ "'반복자2'-1" 위치 범위의 요소 삭제.

< vector 에서의 erase >
// vector에서는 인덱스 파라미터 불가능함.
v.erase(반복자);  // 해당 반복자 위치의 요소만 삭제.
v.erase(반복자1, 반복자2);  // "반복자1" ~ "'반복자2'-1" 위치 범위의 요소 삭제.

-------------

[ erase 응용 예시 ]

< remove 및 erase 해석 및 설명 (string 형식에서) >
my_string.erase(remove(my_string.begin(),my_string.end(),str[0]), my_string.end());
// remove(my_string.begin(), my_string.end(), str[0]): 이 함수는 my_string의 시작부터 끝까지 탐색하면서 str[0]과 일치하는 '모든' 문자를 '전부' "제거"한다. 그런데 여기에서 "제거"는 실제로 해당 요소들을 문자열에서 삭제하는 것이 아니라, 삭제 후 비게된 크기만큼 앞으로 땡겨 이동하여 문자열의 뒷부분을 이외것들로 채우는 것을 의미한다. 즉, remove 후 문자열의 길이는 동일하게 유지되는 것이다. 그리고 remove는 이동이 끝난 후의 마지막 위치의 반복자를 반환한다.
결론적으로, '이동이 끝난 후의 마지막 위치의 반복자' ~ 'end()-1 위치' 까지 삭제를 하는 의미가 되어 해당 문자를 모두 찾아 삭제하게 되는 것이다.
// my_string.erase(...): remove에서 반환된 반복자를 사용하여 my_string에서 해당 위치부터 끝까지의 모든 문자를 "실제로 삭제"한다. 예를 들어, solution("apple", "pp")를 호출하면, str[0]은 'p'이다. 따라서 "apple"에서 'p' 문자를 모두 제거하면 결과는 "ale"가 된다.
이해를 돕기 위해 단계별로 예를 들어 설명해보자면,
원래 문자열: "apple"
remove 후의 문자열: "alele" ('p'가 삭제된만큼 앞으로 땡겨 이동되면서 뒷부분이 이외의것들로 채워진다.)
remove가 반환한 반복자 위치: "ale|le"
erase를 사용하여 "pp"를 삭제한 후의 문자열: "ale" 따라서 함수의 결과는 "ale"이다.

< unique 및 erase 해석 및 설명 (vector 형식에서) >
unique는 '#include <algorithm>' 헤더를 선언해야하며, 벡터의 연속으로 중복된 원소를 제거해주는 역할을 한다.
단, 헷갈리지말아야할점은 전체의 중복요소를 set처럼 제거가 아닌, 연속적으로 나오는값만 각각 하나씩으로 단일화 시켜주는 것이다.
그러한 이유로, 만약 unique 함수를 전체의 중복요소를 set처럼 제거해주는 용도로 사용하고 싶다면, 먼저 sort로 정렬후에 unique를 적용해주면 되는것으로 응용 가능하다.
unique 또한 위의 remove처럼 erase 함수를 추가적으로 이용해야하며, 사용방법은 위와 비슷하다.
v.erase(unique(v.begin(), v.end()), v.end());
이처럼 사용한다.

< 반복문 내에서 erase를 사용하는 팁 예시코드 >
// 밑은 주어진 문자열 value에서 '.'가 연속2번이상 반복되는 부분들을 모두 '.' 하나씩으로 변경하는 함수를 작성해본것이다.
string ReplaceDot(string value)
{
    string result = value;

    int i = 0;
    while(true)
    {
        if(i == result.size()-1)
            break;

        if(result[i] == '.' && result[i+1] == '.')
            result.erase(i, 1);
        else
            i++;
    }

    return result;
}

=======================================

< string >

string str1(i, '*');  // i 개의 '*' 문자를 가진 str1이라는 변수명의 문자열 생성
cout << str1 << "\n";

// 역순 정렬. 참고로 str은 스트링 변수명임.
// 참고로 vector 변수도 마찬가지로 똑같이 적용하면됨.
reverse(str.begin(), str.end());

string str = "TEST"; 일 때
str[0] 은 'T'를 반환. 
str.at(1) 은 'E'를 반환.
두 경우 모두 반환되는 문자는 char형임.

string answer = "";
answer += "k";  // 문자열 추가도 가능함.
answer += 'k';  // 문자 추가도 가능함.
answer += string(n,v);  // 이것처럼 char과는 다르게 string은 문자열을 +로 이을수있으며, (참고로 string(n,v)은 문자 v를 n번 반복한 문자열을 생성함.)
str1.push_back(chr);  // push_back 메소드도 적용이 가능하다. (단 이것은 한문자만 가능함. 문자열은 적용 불가능함.)
str1.push_back(str[0]);  // 위와 비슷한 맥락임.
str1.append(str2);  // str 문자열 맨 뒤에 str2 문자열을 추가함.
str1.append("k");  // 쌍따옴표의 문자는 문자열로 취급되어 append를 사용 가능함. 단, 문자추가인 str1.append('k'); 는 불가능함.
// append는 문자열의 맨 뒤에 추가한다는 점이 push_back과 비슷하지만 차이점이 존재한다. push_back은 "a character" 즉 한 문자만 뒤에 추가할 수 있지만 append는 "characters"로 여러 문자열을 추가 할 수 있다.
// 즉, 문자로 문자열 추가 방식을 사용하려면 "" 쌍따옴표로 나타내서 넣어주면되며, 문자 추가 방식은 '+=', 'push_back()' 이며, 문자열 추가 방식은 '+=', 'append()' 이다.
// 즉, string에서 문자를 추가하고싶다면 'push_back()' 또는 '+=' 또는 '쌍따옴표 append("문자")'를 활용하면 된다. 정 헷갈리면 그냥 += 를 활용하자.

string str_a ="7";
string str_b ="7.02";
string str_c ="3.14";
string str_d = "2300000000";
// 참고로 stoi 이런건 sto + int 이런 뜻이다. 정확히는 stod는 's'tring + 'to' + 'd'ouble, stof는 's'tring 'to' 'f'loat
// 그리고 stoi 이런건 문자열 앞의 -부호 처리도 알아서 변환해주니 바로 사용하면된다.
int after_a = stoi(str_a);  // "7"을 int형 7로 바꿔줌.
double after_b = stod(str_b);  // "7.02"를 double형 7.02로 바꿔줌.
float after_c = stof(str_c);  // "3.14"를 float형 3.14로 바꿔줌.
long int after_d = stol(str_d);  // "2300000000"을 long int형으로 바꿔줌.
long long num = stoll(str);  // 문자열 str을 long long형으로 바꿔줌.

// 다른자료형에서 string으로 변환법 예시
int num = 43;
string s = to_string(num);

// str1에서 문자열or문자 str2를 찾고, 이것의 str1에서의 시작점 인덱스를 반환함. 존재하지않으면 string::npos(== 쓰레기 값)인 4294967295 처럼 반환함.
string str1 = "TEST";
string str2 = "ST";
str1.find(str2);  // 2 반환함. (TEST에서 ST의 S는 2번째 인덱스므로)
str1.find("ST"); // 2 반환함. (주의: 문자열 넣었으므로 큰따옴표로만 사용하기.)
str1.find('S'); // 2 반환함. (주의: 문자 넣었으므로, 'S' 또는 "S" 모두 사용가능.)
auto findIdx = str1.find("ST", idx);  // idx인덱스부터 끝까지 검색함. 찾은 인덱스 혹은 string::npos 를 반환한다.
// 그냥 속편하게 전부 큰따옴표로 통일해서 사용하는것이 나을듯하다.

// 위의 str1.find("ST")와 같은 find함수에서 못찾는경우 예시
    string str = "hello world";
    if (str.find("world") != string::npos)
    {
        cout << "find Success" << "\n";
        cout << "find Index: " << str.find("world") << "\n";
    }
    else {
        cout << "find fail" << "\n";
    }

// string에서는 vector처럼, distance함수를 활용하여, iterator에서의 특정 반복자가 가리키는 string의 실제 인덱스를 구할 수 있다.
// 사용방법은, distance(str.begin(), iter); 을 활용한다. 이는 첫인덱스부터 찾은반복자 사이의 거리를 이용하여 index를 찾는것이다.
// 밑은 예시 코드이다.
string str = "cake";
auto iter = find(str.begin(), str.end(), 'k');
if(iter != str.end()) {
    int idx = distance(str.begin(), iter);  // begin()부터 iter반복자 사이의 거리계산.
    answer = idx;
}
// 물론, 이는 int idx = distance(str.begin(), iter); 대신에
// int idx = iter - str.begin(); 이걸로 사용해도 된다.

string str2 = str1.substr(2);  // index 2의 위치부터 ~ 끝까지의 문자를 반환함.
string str2 = str1.substr(2,3);  // index 2의 위치부터 3개의 문자를 반환함.

str.insert(2,"bbb");  // index가 2인 위치에 있는 문자 앞에 문자열을 삽입함. (문자 삽입 안됨. 할거면 쌍따옴표 사용하기.) 

// replace는 문자말고 문자열로 대체한다. 만약 문자로 대체하고 싶다면, 문자에 쌍따옴표""를 넣어 사용하면 된다.
str.replace(2,3,"bbb");  // index가 2인 위치에 있는 문자부터 ~ 3개의 문자를 "bbb"로 대체함.
// 위의 변환 내용은 aaaaaaaa -> aabbbaaa
str.replace(2,4,"bbb");  // index가 2인 위치에 있는 문자부터 ~ 4개의 문자를 "bbb"로 대체함.
// 위의 변환 내용은 aaaaaaaa -> aabbbaa

string과 vector는 #include<algorithm>헤더의 fill함수를 사용할 수 있다.
fill(반복자1, 반복자2, 채울값);  // "반복자1" ~ "'반복자2'-1" 위치 범위에 채울값 대체.
string str = "abcdef";
fill(str.begin()+1, str.begin()+3, 'z');  // 인덱스1부터 인덱스2까지 'z'로 대체함. (문자만 가능. 문자열은 불가능함.)
// 위의 변환 내용은 abcdef -> azzdef

-------------

// 이 string에서의 erase 함수는 직접적인 인덱스를 파라미터로 줄때와 반복자를 파라미터로 줄때 삭제 방식이 다름.
// 그리고 참고로 str.erase(반복자1, 반복자2); 의 의미는 반복자1의 위치부터 반복자2의 위치전까지 삭제한다는 뜻임. (즉, 반복자1위치 ~ 반복자2위치-1 까지 삭제.)
string str = "0123456789";  // 밑의 메소드 사이사이에 다시 원래값으로 되돌려놓는것으로 가정하고 설명하겠다.

str.erase(2);  // index가 2인 위치에 있는 문자부터 전부 제거함.
// => "01"

str.erase(2,4);  // index가 2인 위치에 있는 문자부터 ~ 4개의 문자를 제거함.
// => "016789"

str.erase(str.begin());  // 0인덱스(첫번째 문자)의 문자만 제거함.
// => "123456789"

str.erase(str.begin() + 1);  // 1인덱스(두번째 문자)의 문자만 제거함.
// => "023456789"

str.erase(str.begin() + 2);  // 2인덱스(세번째 문자)의 문자만 제거함.
// => "023456789"

str.erase(str.end());  // end() 반복자는 마지막의 다음부분을 의미하므로, 아무것도 제거하지 못함.
// => "0123456789"

str.erase(str.end() - 1);  // end()-1 반복자는 마지막 부분을 의미하므로, 마지막 문자만 제거함.
// => "012345678"

str.erase(str.begin(), str.end());  // begin() ~ end()-1 위치까지 삭제하므로, 전체를 삭제함.
// => ""
// 헷갈리지 말아야할것은, end()가 마지막 다음위치를 가리킨다는 것이고, str.erase(반복자1, 반복자2); 에서 반복자2의 의미는 '반복자2'-1 위치까지 제거하겠다는 의미가 된다는 것이다.

str.erase(str.begin(), str.end()-1);  // begin() ~ end()-2 위치까지 삭제하므로, 마지막을 제외한 나머지를 삭제함.
// => "9"

str.erase(str.begin()+1, str.begin()+4);  // begin()+1 ~ begin()+4-1 위치까지 삭제하므로, 1인덱스부터 3인덱스까지 삭제함.
// => "0456789"

string str = "01k234k5";
str.erase(find(str.begin(), str.end(), 'k'));
// => "01234k5"
// find(str.begin(), str.end(), 'k') 의 반환값은 첫번째로 나오는 k문자의 반복자 위치이다.
// 그러므로, str에서 첫번째로 나오는 k문자만 제거한다. 참고로 문자열이 아닌 문자 제거이다.
// 그리고 참고로 str.find()가 아닌 find()이다. str.find()는 문자열을 파라미터로 넣어주고 인덱스를 반환하는 반면, find()는 반복자를 파라미터로 넣어주어야하며 반환값도 반복자가 된다.
// 즉, str.find()가 아닌 find() 함수이기에 인덱스가 아닌 반복자가 반환되어, 해당 인덱스부터 전부 제거의 의미가 아닌, 해당 반복자 위치만 제거의 의미가 된다.

string str = "01k234k5";
str.erase(str.find("k"));
// find()가 아닌 str.find() 함수이기에 반복자가 아닌 인덱스가 반환되어, 해당 반복자 위치만 제거의 의미가 아닌, 해당 인덱스부터 전부 제거의 의미가 된다.
// => "01"

string str = "01k234k5";
str.erase(str.find("k2"));
// find()가 아닌 str.find() 함수이기에 반복자가 아닌 인덱스가 반환되어, 해당 반복자 위치만 제거의 의미가 아닌, 해당 인덱스부터 전부 제거의 의미가 된다.
// => "01"

=======================================

< vector >

vector 도 배열 안의 요소를 복사해서 넣어주는 방식을 사용하므로 지역변수처럼 값이 다시 원래대로 돌아와, 참조를 활용해야한다.

vector 배열을 초기화 시켜주지않았다면, 배열의 인덱스에 직접 접근해서 값을 할당하는건 불가능하다. 이러한 경우에는 push_back으로 넣어주어야한다.
참고로 push_back은 마지막부분에 요소를 추가시키는 반면, pop_back은 마지막부분의 요소를 삭제시킨다.

vector 배열을 초기화 시켜줬다면, 배열의 인덱스에 직접 접근해서 값을 할당하는것도 가능하다.

참고로 vector는 벡터명 그자체를 cout으로 바로 출력은 불가능하다. 예를들어
cout << v << "\n"; 는 불가능하다는 의미이다.

벡터또한 인덱스가 0부터 시작이며, v.begin()+2 는 v[2]인 세번째 인덱스를 의미한다.

erase(v.begin()+1, v.begin()+4); 를 해줌으로써 vector의 1인덱스~3인덱스 요소가 삭제된다.
즉, 인덱스 1 <= 삭제 < 4 로 마지막은 포함되지 않는다.

벡터에서 iterator방식으로 for문으로 순회할시에, *iter 로 실제값에 접근할 수 있으며, iter - v.begin() 로 인덱스를 구할수있다.

벡터에서 erase 및 insert 함수는 요소의 인덱스를 사용하는 것이 아니라 반복자를 파라미터로 넣어 사용해야 한다.

find와 sort와 reverse함수를 사용하려면 #include <algorithm> 헤더를 작성해둬야한다.
STL의 sort함수는 퀵정렬으로써, 시간복잡도가 nlogn이다.

참고로 배열 초기화할때, '= { 7, };' 은 7,0,0,... 이렇게 초기화지 전부 7로 초기화가 아니다. 

- 1차원 벡터의 여러가지 초기화 방법 -
vector<int> v1;  // 아무것도 없는 비어있는 vector
vector<int> v2(5);  // 5개의 int형을 저장하는 vector(전부 0으로 초기화)
vector<int> v3(5,1);  // 5개의 int형을 저장하는 vector(전부 1로 초기화)
vector<int> v4 = { 1,2,3,4,5 };  // 배열과 같은 초기화 (참고로 v4.end()-1 위치가 요소5 부분이다.)
vector<int> v5(v4);  // v4의 벡터 요소를 복사해서 초기화
vector<int> v6(v4.begin(), v4.end());  // v4의 벡터 요소를 begin()부터 end()-1 부분까지 복사해서 초기화. (즉, 전부 복사의 의미와 동일.)
// 아마 위의 v6의 파라미터로 set를 넣어도 될것이다.

- 2차원 벡터의 여러가지 초기화 방법 -
vector<vector<int>> v7 = { {0,1,2}, {3,4,5}, {6,7,8} };
vector<vector<int>> v8 = { {0,1,2}, {3,4,5,6}, {7,8} }; // 어차피 벡터안에 벡터를 집어넣는 개념이므로, 이방식으로 직접 할당초기화해줄땐 벡터사이즈가 전부 동일하지 않아도 된다.
vector<vector<int>> v9(5, vector<int>(4));  // [5][4] 크기에 전부 0을 할당.
vector<vector<int>> v10(5, vector<int>(4,2));  // [5][4] 크기에 전부 2를 할당.
// v10은 마치, 5칸짜리 방 안에 각각 2로 채워져있는 4칸짜리 방을 또 넣는다고 생각하면 된다.

v.front() - 벡터의 첫 번째 요소를 반환한다. (요소 실제값)  // 참고로 v.front()에 값을 직접 할당 또는 연산할당이 가능하다.
v.back() - 벡터의 마지막 요소를 반환한다. (요소 실제값)  // 참고로 v.back()에 값을 직접 할당 또는 연산할당이 가능하다.
v.begin() - 벡터의 첫 번째 요소를 가리킨다. (반복자)
v.end() - 벡터의 마지막 요소를 가리킨다. 정확히말하자면 마지막요소의 다음부분을 가리킨다. (반복자)

// vector에서 insert로 삽입하기
vector<int> v = { 10,10,10,10 };  // 밑의 메소드 사이사이에 다시 원래값으로 되돌려놓는것으로 가정하고 설명하겠다.
v.insert(v.begin()+1, 20);  // 인덱스1 위치앞에 20을 삽입 => 10 20 10 10 10
v.insert(v.begin()+1, 3, 20);  // 인덱스1 위치앞에 20을 3번 삽입 => 10 20 20 20 10 10 10

// vector내에서 해당 원소가 위치하는 인덱스 찾기
find(v.begin(), v.end(), 찾을 대상) - v.begin()

// 밑은 입력받은 num1부터 num2 인덱스의 요소를 가진 벡터를 리턴해야하는 문제의 답코드이다.
vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer(numbers.begin()+num1, numbers.begin()+num2+1);  // 이래야지 begin()+num1 ~ begin()+num2+1-1 부분을 의미하게 된다.
    return answer;
}

// 역순 정렬. 참고로 v는 벡터 변수명임.
// 참고로 string 변수도 마찬가지로 똑같이 적용하면됨.
reverse(v.begin(), v.end());

// 오름차순 정렬. 참고로 v는 벡터 변수명임.
sort(v.begin(), v.end());
sort(v.begin(), v.end(), less<int>());
// 참고로 v벡터가 아니라 arr배열인경우(길이5짜리), sort(arr, arr+5);

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

#include <algorithm> 헤더의 count 또는 count_if 함수를 활용하여 원소를 개수를 반환받는 방법이 있다.
이 함수 사용방법은 #include <algorithm> 헤더의 find, find_if 함수와 사용방법이 유사하다.
// 밑은 코드 예시이다.
cout << "원소 num의 개수: " << count(v.begin(), v.end(), num);
cout << "홀수인 원소의 개수: " << count_if(v.begin(), v.end(), isOdd);

// 벡터 배열 max 값 구하는법
int max = *max_element(v.begin(), v.end());  // 만약 일반 배열이라면, 'int max = *max_element(&arr[0], &arr[마지막인덱스+1])' 이렇게 사용이 가능하다.
// 그 이유는 begin과 end는 요소의 값을 반환하는게 아닌 요소를 가리키는것 뿐이기때문인데, 그렇기에 *포인터를 붙여서 벡터에서 최댓값을 가리키는 반복자가 가리키는 값을 반환하는 것이다.
// 만약 *포인터를 뺐다면 최댓값을 가리키는 반복자를 반환하는 것이기에 에러가 난다.
// 참고로 이는 #include <algorithm> 헤더를 작성해야 사용가능하다.

// 백터 배열 max 인덱스 구하는법
int max_index = max_element(v.begin(), v.end()) - v.begin();
// 'max_element(v.begin(), v.end())' - 'v.begin()' 인것이다.
// 그 이유는 최댓값을 가리키는 반복자와 벡터의 시작 위치를 가리키는 반복자 간의 차를 계산함으로써, 최대 인덱스를 구하는 것이기 때문이다.
// 참고로 이는 #include <algorithm> 헤더를 작성해야 사용가능하다.

// vector에서는 string처럼, distance함수를 활용하여, iterator에서의 특정 반복자가 가리키는 vector의 실제 인덱스를 구할 수 있다.
// 사용방법은, distance(v.begin(), iter); 을 활용한다. 이는 첫인덱스부터 찾은반복자 사이의 거리를 이용하여 index를 찾는것이다.
// 밑은 예시 코드이다.
vector<int> seoul = { 34,52,12,98 };
auto iter = find(v.begin(), v.end(), 12);
if(iter != v.end()) {
    int idx = distance(v.begin(), iter);  // begin()부터 iter반복자 사이의 거리계산.
    answer = idx;
}
// 물론, 이는 int idx = distance(v.begin(), iter); 대신에
// int idx = iter - v.begin(); 이걸로 사용해도 된다. (마치 max_index 구할때처럼.)

map으로 반복문을 사용할때는 반복문 소괄호 매개변수 안에 각 인덱스로 map[i]를 접근하는 방법이 아닌, iterator로 요소에 접근해야한다. 반면 vector은 반복문에서 각 인덱스로도 접근이 가능하다.

rotate 함수는 벡터의 값들을 마치 회전시키듯 지정된 횟수만큼오른쪽으로 회전시키거나, 왼쪽으로 회전할 수 있다.
rotate 함수 사용을 위해선 #include <algorithm> 헤더를 작성해둬야한다.
컨테이너에 원소가 많이 존재하거나 하는 경우에는 매우 비효율적이며 특수한 경우가 아닌 경우 사용을 지양해야 한다.

rotate 함수는 인자로 (시작 반복자, 첫 위치로 오게할 Forward 반복자, 종료 반복자) 를 받는다.
vector<int> v = { 10, 20, 30, 40, 50 };  // 밑의 메소드 사이사이에 다시 원래값으로 되돌려놓는것으로 가정하고 설명하겠다.
rotate(v.begin(), v.begin() + 1, v.end());  // 1칸씩 왼쪽 이동 => 20 30 40 50 10
rotate(v.begin(), v.begin() + 2, v.end());  // 2칸씩 왼쪽 이동 => 30 40 50 10 20
rotate(v.begin(), v.end() - 1 , v.end());  // 1칸씩 오른쪽 이동 => 50 10 20 30 40
rotate(v.begin(), v.end() - 2 , v.end());  // 2칸씩 오른쪽 이동 => 40 50 10 20 30

// 2차원 벡터 초기화 예시
    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));

// 할당없이 이미 선언만된 2차원 벡터 가변 크기 설정 예시
vector<vector<int>> v;
int n=2, m=3;
v.resize(n, vector<int>(m));  // (m,0)방식으로도 사용가능.

// 할당없이 이미 선언만된 1차원 벡터 가변 크기 설정 예시
vector<int> v;
int n=2
v.resize(n);  // (n,0)방식으로도 사용가능.

// swap 예시
swap(v[2], v[4]);
iter_swap(v.begin()+2, v.begin()+4);

vector<pair<int,int>> adj[1002];  // 이거 구조 특이함. 값꺼낼땐 마치 'vector<vector<pair<int,int>>> adj'와 동일함.
adj[start].push_back({end, dist});  // 이렇게되면 adj[start]에 여러 pair가 쌓이므로, 차후엔 adj[주요인덱스][쌓이는만큼인덱스].first 이런식으로 불러내야한다.

-------------

< 일반array와 vector 에서의 fill함수 사용법 >

// 1차원 vector fill함수
vector와 string은 #include<algorithm>헤더의 fill함수를 사용할 수 있다.
fill(반복자1, 반복자2, 채울값);  // "반복자1" ~ "'반복자2'-1" 위치 범위에 채울값 대체.
vector<int> v = { 0,0,0,0,0 };
fill(v.begin()+1, v.begin()+3, 5);  // 인덱스1부터 인덱스2까지 5로 대체함.
// 위의 변환 내용은 0,0,0,0,0 -> 0,5,5,0,0

// 2차원 vector fill함수
vector<vector<int>> v(5, vector<int>(4,2)); 가 선언되어있다면,  // 대강 v[5][4] 안이 전부 2로 초기화 되어있는 벡터라고 보면된다.
fill(v.begin(), v.end(), vector<int>(4,0));  // 또는 fill(v.begin(), v.end(), vector<int>(4));
// 이는 마치 5칸짜리 방 안에 각각 0으로 채워져있는 4칸짜리 방을 다시 넣는다고 생각하면 된다.

// 1차원 일반array fill함수
int arr[5]; 가 선언되어있다면,  // int arr[5] = { 1,2,3,4,5 }; 이런식으로 되어있어도 상관없다. 참고로 당연히 인덱스목록은 0,1,2,3,4 까지 있다.
fill(arr, arr + 5, 9);  // "0인덱스" ~ "'5-1'인덱스" 위치 범위에 채울값 9로 대체.
fill(&arr[0], &arr[5], 9);  // fill(arr, arr + 5, 9); 의 주석설명과 동일하다.
// 위는 결국 9,9,9,9,9 가 된다. 이처럼 전체 초기화해서 배열 전체 출력해줄것이 아니라면 미리 배열을 할당해준뒤에 fill 사용을 하는것이 좋다.
// 만약 할당도 이미 되어있는 배열이라면, 예시로 fill(arr + 1, arr + 3, 9); 을 적용하고 전체 출력해도 쓰레기값이 안나온다.

// 2차원 일반array fill함수
int arr[9][6];  // 참고로 당연히 인덱스목록은 [8][5] 까지 있다.
fill(&arr[0][0], &arr[8][6], 9);  // 처음부터 끝까지 9로 채울값 대체.
// 위에서 &arr[8][6] 는, &arr[8][5+1] 으로 작성한것이다. 꼭 이러한 방식으로 작성해야하니 주의하자.

// 3차원 일반array fill함수
int arr[3][4][2];  // 참고로 당연히 인덱스목록은 [2][3][1] 까지 있다.
fill(&arr[0][0][0], &arr[2][3][2], 9);  // 처음부터 끝까지 9로 채울값 대체.
// 위에서 &arr[2][3][2] 는, &arr[2][3][1+1] 으로 작성한것이다. 꼭 이러한 방식으로 작성해야하니 주의하자.

-------------

< vector 에서의 커스텀 정렬방법 예시 >

// 문제내용: numlist 배열(벡터)을 n과 거리가 가까운 숫자를 우선시로 정렬시키고, 만약 거리가 같을경우 큰 숫자를 앞으로 오게함.

bool compare(int prev, int next) {
    if (abs(prev - num) == abs(next - num))  // 거리가 같을 경우
        return prev > next;
        // 숫자가 큰거 다음 작은거 순으로 오게 해라! (거리 오름차순 하면서 거리 동일시, 숫자 내림차순)
    else  // 거리가 같지않을 경우
        return abs(prev - num) < abs(next - num);
        // 거리가 작은거 다음 큰거 순으로 오게 해라! (기본 거리 오름차순)
        // 참고로 이는 거리가 가까울수록 거리숫자가 작기 때문이다.
}

vector<int> solution(vector<int> numlist, int n) {
    num = n;
    sort(numlist.begin(), numlist.end(), compare);
    return numlist;
}

// - compare 함수의 반환값이 true일 경우:
// 첫번째 인자가 두번째 인자보다 "작다"는 것을 의미함.
// 이 경우, 첫번째 인자가 두번째 인자보다 앞에 위치하도록 함.
// - compare 함수의 반환값이 false일 경우:
// 첫번째 인자가 두번째 인자보다 "크거나 같다"는 것을 의미함.
// 이 경우, 두번째 인자가 첫번째 인자보다 앞에 위치하도록 함.
// ==> 결론: 즉, true면 순서 그대로 유지하고, false면 둘의 순서를 뒤바꾼다.
// 즉, 순서가 원하는대로 오도록 false일경우 뒤바꿔서 재배치하겠다는 의미인것이다.

-------------

< vector 에서의 커스텀 정렬방법 + 전역변수 사용 예시 >

// 문제내용: 문자열들이 들어있는 strings 벡터를 각 문자열의 인덱스n을 기준으로 우선시로 오름차순 정렬시키고, 만약 인덱스n의 알파벳이 같을경우 사전순으로 문자열을 오름차순 정렬시킴.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

bool compare(string a, string b) {
// const랑 &는 빼도 되긴 하다. 하지만 이처럼 string 이나 pair<int, int> 같은 STL 혹은 클래스 객체를 파라미터 전달시에는
// const랑 &를 붙여서 참조시켜주는것이 복사해서 비교하는것을 막아서 불필요한 연산을 막고 시간을 단축시켜 보다 효율적이다.
// 하지만 const는 코딩테스트에서 딱히 불필요하기에, 결론적으로말하자면 &만 붙여줘도 좋다.
    if (a[idx] == b[idx]) {  // 1차 동일시 2차 비교: 문자열 오름차순 정렬
        return a < b;
    }
    else {
        return a[idx] < b[idx];  // 1차 비교: 인덱스 문자 기준 오름차순 정렬
    }
}

vector<string> solution(vector<string> strings, int n) {
    
    idx = n;
    
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}

// - compare 함수의 반환값이 true일 경우:
// 첫번째 인자가 두번째 인자보다 "작다"는 것을 의미함.
// 이 경우, 첫번째 인자가 두번째 인자보다 앞에 위치하도록 함.
// - compare 함수의 반환값이 false일 경우:
// 첫번째 인자가 두번째 인자보다 "크거나 같다"는 것을 의미함.
// 이 경우, 두번째 인자가 첫번째 인자보다 앞에 위치하도록 함.
// ==> 결론: 즉, true면 순서 그대로 유지하고, false면 둘의 순서를 뒤바꾼다.
// 즉, 순서가 원하는대로 오도록 false일경우 뒤바꿔서 재배치하겠다는 의미인것이다.

=======================================

< pair >

pair는 2개를 묶어주는 구조체이다. (3개 이상을 묶고싶다면, tuple을 사용하자.)
pair은 utility 헤더에 존재하며, 프로그래머스에서는 아마 vector 헤더로 대체 가능한듯 하다.

마치 map과 비슷하다. 단, pair은 map과 다른 점이라면 key값이 중복될 수 있다. 반면 map은 key값이 중복될 수 없다.

make_pair(1,2) 이것과 {1,2}는 같은 맥락이다.
pair끼리 비교도 가능하다. pair끼리 비교를 하면 first를 기준으로 먼저 비교를 하게 된다. first가 같다면 second를 비교하게 된다.
pair.first와 pair.second 이런식으로 접근한다.
sort() 역시 사용이 가능하며 sort도 first를 기준으로 먼저, 그 다음 second를 기준으로 정렬을 한다.

// pair 초기화 방법들 예시
pair<int,int> p = {6,7};
pair<int,int> p = make_pair(6,7);
pair<int,int> p = pair<int,int>(6,7);

pair과 map의 for문 관련해서 화살표와 온점 사용방식을 따로 밑쪽 부분에 작성해두었다.

pair<pair<string, int>, string> p1;
p1 = make_pair(make_pair("first string",2), "second string");

-------------

< for문에서의 pair와 map 요소 접근 방법 >

pair 객체는 온점 방식으로 접근해야한다.
map은 안의 요소가 pair객체로 이루어져있다는것을 명심해야한다.
그렇기에 map을 :요소접근 for문으로 접근할시에는 pair객체가 되어 온점을 사용해야하는것이다.
iterator반복자는 반복자이기에 화살표 방식으로 접근해야한다. 반복자가 아닌 :요소접근 방식처럼 접근하고싶다면, (*iter) 처럼 만들어서 pair 객체에 직접 접근할수있도록 만들어주면된다.

map<int, int> map1;

map1을 iterator반복자 for문으로 접근할시,
iter->first 처럼 화살표만 가능하다. 온점인 iter.first 는 불가능하다.
단, (*iter).first 처럼 반복자를 직접 map안의 pair요소에 접근하는 방식으로 바꿔준다면 온점으로 사용가능하다.
    for (auto iter = map1.begin(); iter != map1.end(); iter++)
    {
        cout << iter->first << ", " << iter->second << "\n";  // 화살표 방식만 가능.
        cout << (*iter).first << ", " << (*iter).second << "\n";  // 이렇게하면 반복자로도 온점 방식으로 사용 가능.
    }

map1을 :요소접근 for문으로 접근할시,
p.first 처럼 온점만 가능하다. 화살표인 p->first 는 불가능하다.
    for (auto p : map1)
    {
        cout << p.first << ", " << p.second << "\n";  // 온점 방식만 가능.
    }

즉, pair와 map의 접근방식을 요약 정리하자면
pair은 온점 방식만 사용하자.  // a.first
map은 for문에서 iterator반복자 접근시, 화살표 방식만 사용하자.  // iter->first
map은 for문에서 iterator반복자 접근시 포인터를 활용한다면, 온점 방식만 사용하자.  // (*iter).first
map은 for문에서 :요소접근으로 접근시, 온점 방식만 사용하자.  // p.first

-------------

< pair 와 vector >

pair<vector<int>, string> p2;
vector<int> arr = { 1,3,5 };
p2 = make_pair(arr, "vector pair");

// vector<int> emergency를 파라미터로 전달받은상태라는걸 가정하에,
    vector<pair<int, int>> sorted_emergency;
    for (int i = 0; i < emergency.size(); i++) {
        sorted_emergency.push_back({emergency[i], i});  // emergency 배열을 인덱스와 함께 마치 map형식처럼 바꿔서 새로 만듦.
    }
    sort(sorted_emergency.rbegin(), sorted_emergency.rend());

-------------

< pair 에서의 first,second 커스텀 정렬방법 예시 >

// pair에서의 first 오름차순과 second 내림차순 정렬해주는 함수
bool compare(const pair<int, int>& a, const pair<int, int>& b)
// const랑 &는 빼도 되긴 하다. 하지만 이처럼 string 이나 pair<int, int> 같은 STL 혹은 클래스 객체를 파라미터 전달시에는
// const랑 &를 붙여서 참조시켜주는것이 복사해서 비교하는것을 막아서 불필요한 연산을 막고 시간을 단축시켜 보다 효율적이다.
// 하지만 const는 코딩테스트에서 딱히 불필요하기에, 결론적으로말하자면 &만 붙여줘도 좋다.
{
    if (a.first == b.first)  // 만약 first 값이 같다면,
    {
        return a.second > b.second;
        // second가 큰거 다음 작은거 순으로 오게 해라! (first 오름차순 하면서 first 동일시, second 내림차순)
    }
    else  // 만약 first 값이 같지 않다면,
    {
        return a.first < b.first;
        // first가 작은거 다음 큰거 순으로 오게 해라! (기본 first 오름차순)
    }
}

int main()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(1, 2));
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(2, 0));
    v.push_back(make_pair(2, 2));
 
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < 4; ++i)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}

// 밑은 출력 결과
1 2
1 0
2 2
2 0

// - compare 함수의 반환값이 true일 경우:
// 첫번째 인자가 두번째 인자보다 "작다"는 것을 의미함.
// 이 경우, 첫번째 인자가 두번째 인자보다 앞에 위치하도록 함.
// - compare 함수의 반환값이 false일 경우:
// 첫번째 인자가 두번째 인자보다 "크거나 같다"는 것을 의미함.
// 이 경우, 두번째 인자가 첫번째 인자보다 앞에 위치하도록 함.
// ==> 결론: 즉, true면 순서 그대로 유지하고, false면 둘의 순서를 뒤바꾼다.
// 즉, 순서가 원하는대로 오도록 false일경우 뒤바꿔서 재배치하겠다는 의미인것이다.

=======================================

< tuple >

#include <tuple> 헤더를 선언해야한다.

tuple은 pair와 비슷하지만 2개보다 더 많은 데이터를 묶을 수 있다. (2개 이상이므로, pair처럼 2개도 가능하긴함.)
tuple은 여러개를 묶을수 있기에,
보통 2개의 데이터를 묶을 때는 std::pair을 사용하고, 3개 이상이면 std::tuple를 사용한다.
함수의 반환값으로 3개 이상의 값을 반환하고자 할때에도 사용하면 좋다.

tuple의 요소접근은, tuple의 인덱스에 접근할 때 get<> 사이에 변수를 넣을 수 없다.
예시로 for (int i=0; i<3; i++) cout << get<i>(t) << "\n"; 는 사용불가능하다는 것이다.
일일이 get<0>(t1) 이런식으로 불러줘야한다.

// tuple 초기화 방법들 예시
tuple<int,int,int> t = {6,7,8};
tuple<int,int,int> t = make_tuple(6,7,8);
tuple<int,int,int> t = tuple<int,int,int>(6,7,8);

// 튜플 사용 예시코드
int main(){
    tuple<int, string, int> t1 = make_tuple(10, "hi", 30);  // = { 10, "hi", 30 }; 으로 할당도 가능.
    cout << get<0>(t1) << "\n";  // 10 출력
    cout << get<1>(t1) << "\n";  // hi 출력
    cout << get<2>(t1) << "\n";  // 30 출력
    // 만약 tuple 크기가 4개였다면, get<3>(t1)도 가능함.

    get<2>(t1) = 90;
    cout << get<2>(t1) << "\n";  // 90 출력

    int x, z;
    string y;
    tie(x, y, z) = t1;  // 튜플의 값을 가져와서 한번에 변수에 할당.
    cout << x << "\n";  // 10 출력
    cout << y << "\n";  // hi 출력
    cout << z << "\n";  // 90 출력
}

=======================================

< map >

map은 각 노드가 key와 value 쌍으로 이루어진 트리이다. 특히, 중복을 허용하지 않는다.
map은 key를 기준으로 정렬하며 오름차순으로 정렬한다.
#include <map>
map<key, value> map1;
- 오름차순 기본형태: map<int, string> map1;
- 내림차순 형태 예시1: map<int, string, greater<int>> map1;
- 내림차순 형태 예시2: 데이터에 -(마이너스)를 붙여 삽입하여 처리하면 내림차순으로 정렬된다.

map1.insert(make_pair(10, 20));
map1.insert({key,value});
map1.insert({{key1,value1}, {key2, value}});

    unordered_map<int, int>::iterator iter;  // 물론 밑의 for문 안에 한번에 작성도 가능하긴하다. 아니면 쉽게 auto iter로 작성해도될듯하다.
    for (iter = map1.begin(); iter != map1.end(); iter++)
    {
        cout << iter->first << " " << iter->second << "\n";
    }

map으로 반복문을 사용할때는 반복문 소괄호 매개변수 안에 각 인덱스로 map[i]를 접근하는 방법이 아닌, iterator로 요소에 접근해야한다. 반면 vector은 반복문에서 각 인덱스로도 접근이 가능하다.
즉, map 반복문 순회는 vector나 array랑 다르게 index가 아닌 iterator를 사용한다.
단, for(auto keyvalue : map1) { keyvalue.first 및 keyvalue.second 사용 } 이런식의 for 루프 순회는 가능하다.
그래도 map은 insert없이 m[i] = "값" 으로만 적어도 없는지 확인하고 없으면 삽입한다.
위의 방법으로 조회와 수정도 가능하다.
단, vector iterator 처럼 iter[3] 같이 map이 아닌 iterator로는 임의접근 안된다. 즉, iter[3]은 안되고 map[3]은 가능하단 뜻이다.

map의 원소는 pair 객체로 저장되며,
pair 객체의 first 멤버 변수는 key로 second 멤버 변수는 value이다.
for (iter = m.begin(); iter != m.end(); iter++) { } 에서
key는 iter->first, value는 iter->second 이다.
하지만 for(auto keyvalue : m) 이런식의 for문인 경우에는 ->말고 .으로 사용하여 keyvalue.first 이런식으로만 사용해야한다.

map과 pair의 for문 관련해서 화살표와 온점 사용방식을 따로 위쪽인 pair파트쪽에 작성해두었다.

사용자가 map객체에 주어진 값의 쌍이 있는지 확인해야하는 경우 멤버 함수 count를 사용할 수 있다.
map에 키가 있으면 맵 컨테이너의 모든 키가 고유하므로 개수는 정확히 1이 된다. 반면에 키를 찾을 수 없으면 count 함수는 0을 반환한다.
    if (m.count(key)) {
        cout << "Key Exists!" << endl;
    } else {
        cout << "Key does not exist!" << endl;
    }

그리고 map은 map 헤더에 존재하며, pair와 동일하게 사용할 수 있다. pair과 다른 점이라면 key값이 중복될 수 없다.
반면 pair은 utility 헤더에 존재하며, pair는 2개를 묶어주는 구조체이다.

-------------

< map vs unordered_map >

- map:
#include <map>
map<int, int> map1;
pair<const Key, T> 로 이루어진 컨테이너임.
Key값 기준으로 기본적으로 오름차순 sorting 되어있음.
균형 이진탐색트리중에서 레드블랙트리로 구현되면서 sorting하므로 unordered_map보다 value값을 찾는 데에 오래걸릴 수 있음.
데이터가 N개일때 탐색속도는 O(logN)임.
map은 데이터 양이 보다 적을때와 Key를 이용하여 정렬을 해야할때 권장한다.

- unordered_map:
#include <unordered_map>
unordered_map<int, int> map1;
map과는 달리 Key 혹은 Value 기준으로 sorting 되어있지 않은 컨테이너임.
hash table 기반 hash container임. (Average: O(1)) 우리가 흔히 사용하는 hash 자료구조에 해당된다고 보면 됨.
Key값으로 hash value를 찾는 데에 시간이 적게 걸림.
데이터가 N개일때 탐색속도는 O(1)임.

map은 데이터 양이 보다 적을때와 Key를 이용하여 정렬을 해야할때 권장한다.
unordered_map은 대량의 데이터를 저장할때와 정렬이 필요없을때 권장한다.
즉, 정렬이 필요 없을 경우에는 map보다는 unordered_map을 사용하는 것이 훨씬 성능이 좋다.

=======================================

< set >

연관 컨테이너중 하나임.
key(요소)값은 중복이 허용되지않음.
자동으로 오름차순 정렬해줌.
#include <set>
set<int> s;
- 오름차순 기본형태: set<int> set1;
- 내림차순 형태 예시: set<int, greater<int>> set1;

참고로 그저 순서가 정렬되어있지않은 set을 사용하고싶다면,
'#include <unordered_set>' + 'unordered_set<int> s'을 사용하자. 사용법은 일반적인 set와 동일하다.

set<int> s = { 1,2,3,4,5 };
s.insert(4);

set는 배열처럼 s[3] 이런식으로 인덱스로 접근할 수 없다.
set를 순회하고 싶다면 밑과 같이 해야한다.
for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
	cout << *iter << " ";
}

find시에 find()말고 set1.find() 사용해야하며, 반환값은 인덱스가 아닌 반복자이다.

사용자가 set객체에 주어진 값의 쌍이 있는지 확인해야하는 경우 멤버 함수 count를 사용할 수 있다.
set에 키가 있으면 맵 컨테이너의 모든 키가 고유하므로 개수는 정확히 1이 된다. 반면에 키를 찾을 수 없으면 count 함수는 0을 반환한다.
    if (s.count(key)) {
        cout << "Element Exists!" << endl;
    } else {
        cout << "Element does not exist!" << endl;
    }

위의 s.count() 함수 외에도
#include <algorithm> 헤더의 count 또는 count_if 함수를 활용하여 원소를 개수를 반환받는 방법도 있다.
이 함수 사용방법은 #include <algorithm> 헤더의 find, find_if 함수와 사용방법이 유사하다.
// 밑은 코드 예시이다.
cout << "원소 num의 개수: " << count(s.begin(), s.end(), num);
cout << "홀수인 원소의 개수: " << count_if(s.begin(), s.end(), isOdd);

=======================================

[ find 관련 예시 ]

-------------

< vector에서의 find 단일찾기 응용방식 (auto 사용) >

#include <iostream>
#include <algorithm>  // std::find
#include <vector>  // std::vector

using namespace std;

int main(){
	vector<int> v = {10, 20, 30, 40, 50};

	auto it = find(v.begin(), v.end(), 30);  // vector<int>::iterator it

	if(it == v.end()) {
		cout << "해당하는 값을 탐색할 수 없습니다.\n";
	}
	else {
		cout << "value is " << *it << endl;	
		cout << "index is " << it - v.begin() << endl;
	}

	return 0;
}

-------------

< vector에서의 find 전부찾기 간단 응용방식 (auto 미사용) >

#include <iostream>
#include <algorithm>  // std::find
#include <vector>  // std::vector

using namespace std;

int main(){
    vector<int> v = {10, 20, 30, 40, 50, 30, 80};

    vector<int>::iterator it = find(v.begin(), v.end(), 30); // auto it

    while(it != v.end()) {
        cout << "value is " << *it << endl;
        cout << "index is " << it - v.begin() << endl;

        it = find(it+1, v.end(), 30);
    }

    return 0;
}

-------------

< vector에서의 find 전부찾기 복잡 응용방식 (+ find_if) >

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isOdd(int n) {
    return n%2==1;
}

int main() {
    vector<int> v = { 46, 67, 184, 4, 17, 53 };

    int num = 4;
    auto it = find(v.begin(), v.end(), num);
    if (it == v.end()) {
        cout << num << "은 찾을 수 없습니다.\n";
    }
    else {
        cout << num << "는 존재하며 인덱스는 " << it - v.begin() << " 입니다.\n";
    }
    cout << "\n==============================\n";

    cout << "홀수(Odd)들 \n";
    auto it2 = find_if(v.begin(), v.end(), isOdd);  // find_if로 bool 결과에따른 해당 반환자 반환. 없으면 end() 반환.
    while (it2 != v.end()) {
        cout << *it2 << "\n";  // 포인터로 실제값 가져오기
        it2 = find_if(it2+1, v.end(), isOdd);
    }

    return 0;
}

-------------

< map에서의 find 전부찾기 응용방식 (+ 문자열 sstream, eof) >

string solution(string morse) {
    string answer = "";
    stringstream ss(morse);
    string s;

    map<string,char> m = {
        {".-",'a'},{"-...",'b'},{"-.-.",'c'},{"-..",'d'},...
        // 위는 생략.
    };

    while (!ss.eof()) {  // 스트림이 끝에 닿을때까지 계속 이어서 반복검색.
        ss >> s;  // ss스트림에 할당한 morse에서 공백이나 엔터가 나오면 변수 s에 할당.
        auto iter = m.find(s);  // map에서 검색. map은 연관 컨테이너이므로, find()말고 map.find()로 사용해야한다. str.find()는 인덱스를 반환하는반면, find() 반환값처럼 map.find()도 반복자를 반환한다.
        if(iter != m.end()) {
            answer += t->second;
        }
    }
    return answer;
}

=======================================

< 문자열을 나누는 stringstream 헤더 >

#include <sstream>

주어진 문자열에서 필요한 자료형에 맞는 정보를 꺼낼 때 유용하게 사용됨.
stringstream에서 공백과 '\n'을 제외하고 문자열에서 맞는 자료형의 정보를 빼낸다.

참고로 커서이동 응용방법도 있다.
string str2 = "a2b";
stringstream stream2(str2);
int num; char ch1; char ch2;
stream2 >> ch1;  // => a
num = stream2.get();  // 커서를 오른쪽으로 이동 => 2 (참고로 맨처음에 'stream2 >> ch1;'없이 바로 get 호출하면 첫위치로 뜸)
ch2 = stream2.get();  // 커서를 오른쪽으로 이동 => b
cout << stream2.unget();  // 커서를 왼쪽으로 이동 => 2

헷갈리지말아야할것은, 이는 char문자 형식으로 추출이 아닌, string문자열 형식으로 추출한다.
밑은 그 예시다.

 #include <string>
 #include <sstream>
 #include <iostream>
 int main() {
    int num;
    string s;
    string str1 = "123 456", str2 = "hello world!";

    // 초기화 방법 1
    stringstream stream1;
    stream1.str(str1);  // stream1에 str1을 대입함으로써 초기화. 

    //초기화 방법 2
    stringstream stream2(str2);  // stream2에 str2을 대입함으로써 초기화. 

    // while 조건 안의 >>의 의미는, 스트림으로부터 값을 읽고, 읽은 값이 성공적으로 저장(찾으면)되면 true를 반환하고, 읽을 수 있는 값이 없다면(스트림의 끝에 도달하거나 오류가 발생하면) false를 반환함. 그리고 동시에 해당 변수인 num에 검색한 값을 할당시킴.
    // 참고로 아마도 이는 while(!stream1.eof()) { stream1 >> num; } 이런식으로도 사용가능할것이다.
    while(stream1 >> num){
      cout << num << endl;
    }

    while(stream2 >> s){
      cout << s << endl;
    }
 }

-------------

< stringstream 응용 예시코드 >

#include <string>
#include <sstream>

using namespace std;

int solution()
    string my_string = "3 + 7 - 5";
    stringstream ss(my_string);

    int result;
    ss >> result;  // ss에서 맨처음나온 반환값을 result변수에 할당.

    char op; int num;
    while (!ss.eof()) {  // 또는 while(ss >> op >> num) 이렇게 한번에 적어도됨. 단, 이문제의경우에선 while(ss >> num >> op)은 에러가난다.
        ss >> op;  // ss에서 나온 반환값중 char 자료형인 값은 op변수에 할당.
        ss >> num;  // ss에서 나온 반환값중 int 자료형인 값은 num변수에 할당.
	// 단, 위의 할당 순서를 잘 지켜주어야한다. 이문제의경우에선 ss >> num; ss >> op; 이 순서로 진행하면 에러가 난다.
	// 참고로 ss >> op >> num;로 작성도 가능하다. 단, 이문제의경우에선 ss >> num >> op;은 에러가난다.

        if (op == '+') result += num;
        else result -= num;
    }

    return result;  // my_string 연산결과값
}

=======================================

배열(벡터)의 요소의 합을 구하는 함수 accumulate
#include <numeric>
accumulate(시작, 끝, 하나씩 더할 값의 초깃값 sum 초깃값);
int sum = accumulate(v.begin(), v.end(), 0);
double sum = accumulate(v.begin(), v.end(), 0.0);

제곱 pow, 제곱근(루트) sqrt
#include <cmath>
pow(10, 2)  // 10의 2제곱 = 100
sqrt(9)  // 루트 9 = 3
// 참고로 powf, powl 이라는것도 있다.
// double pow(double x, double y);
// float powf(float x, float y);
// long double powl(long double x, long double y);

min, max
#include <algorithm>
int maxN = max(value1, value2);  // 참고로 변수명을 max로 해서는 안됨.
int maxN = max({value1, value2, value3});  // 참고로 변수명을 max로 해서는 안됨.
// 꿀팁으로, minVlaue = 1e9 와 maxValue = -1 이런식으로 선언해두고 비교해나가는게 좋다.

영어 소문자,대문자로 변환
#include <cctype>  // 근데 이거 헤더 선언안해도 잘실행되는듯? 하다.
ch = tolower(ch);  // 소문자로 변환
ch = toupper(ch);  // 대문자로 변환

해당 문자가 정수형 문자인지('0'~'9'인 char문자인지) bool 확인
#include <cctype>
string str = "ab12cd4e5";
    for(auto& ch : str)
    {
        if(isdigit(ch))  // '0'~'9'인 char문자가 맞다면
        {
            // 코드 생략
        }
    }

=======================================

```