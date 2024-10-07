#include <string>
#include <vector>
#include <tuple>
#include <cctype>
#include <algorithm>

using namespace std;

// - 최대 시간복잡도 : 100글자 x 1000파일 = 100000 (1억 미만)

// // 참고로 난 tuple의 정렬 특징을 활용하기때문에 밑의 compare함수를 사용하지 않았음.
// // 또는 stabe_sort()를 활용할것.
// string h1,h2;
// int n1,n2,i1,i2;
// bool compare(tuple<string,int,int>& tu1, tuple<string,int,int>& tu2) {
//     h1=get<0>(tu1), h2=get<0>(tu2);
//     n1=get<1>(tu1), n2=get<1>(tu2);
//     i1=get<2>(tu1), i2=get<2>(tu2);
    
//     if(h1 != h2) return h1 < h2;
//     else {
//         if(n1 != n2) return n1 < n2;
//         else return i1 < i2;  // 기존 순서를 그대로 유지.
//         // 참고로 윗줄 코드를 'return true'로 작성하면 틀림.
//         // 만약 true로 쓰고싶다면 stable_sort()를 활용해야함. 이 경우에는 compare 파라미터의 &도 없애야함.
//     }
// }

vector<string> solution(vector<string> files) {
    vector<tuple<string, int, int>> v;  // <head, number, index>
    
    for(int fileIdx=0; fileIdx<files.size(); fileIdx++) {
        string str = files[fileIdx];
        string head = "", number = "";
        int idx = 0;
        
        // head
        for(int i=0; i<str.size(); i++) {
            if(!isdigit(str[i])) {
                head += tolower(str[i]);
            }
            else {
                idx = i;
                break;
            }
        }
        
        // number
        for(int i=idx; i<str.size(); i++) {
            if(isdigit(str[i])) {
                number += str[i];
            }
            else {
                break;
            }
        }
        
        v.push_back(make_tuple(head, stoi(number), fileIdx));
    }
    
    // stable_sort(v.begin(), v.end(), compare);
    // sort(v.begin(), v.end(), compare);
    sort(v.begin(), v.end());  // tuple의 정렬 특징을 활용하여, 굳이 compare을 사용하지 않았음.
    
    vector<string> answer;
    for(auto& tu : v) {
        answer.push_back(files[get<2>(tu)]);
    }
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}