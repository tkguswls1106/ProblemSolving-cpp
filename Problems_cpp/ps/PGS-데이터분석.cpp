#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int extIdx = 0;
int sortIdx = 0;
int getIdx(string str) {
    int idx = 0;
    if(str == "date") idx = 1;
    else if(str == "maximum") idx = 2;
    else if(str == "remain") idx = 3;
    return idx;
}

bool compare(vector<int>& a, vector<int>& b) {
    // 어차피 문제에 명시된 점으로, 정렬 기준에 해당하는 값이 서로 같은 경우는 없다.
    return a[sortIdx] < b[sortIdx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    extIdx = getIdx(ext);
    sortIdx = getIdx(sort_by);
    
    vector<vector<int>> answer;
    for(int i=0; i<data.size(); i++) {
        if(data[i][extIdx] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}