#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    // 합병정렬MergeSort는 각 구역이 정렬된 상태로 시작해야하지만,
    // 어차피 이 문제에서는 정렬된 상태로 각각의 배열을 입력받으므로, 따로 이부분은 코드작성 해줄필요 없다.
    deque<int> a;
    deque<int> b;
    vector<int> resultV;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }
    for(int i=0; i<m; i++) {
        int input;
        cin >> input;
        b.push_back(input);
    }

    while(true) {
        if(!a.empty() && !b.empty()) {
            if(a.front() <= b.front()) {  // Stable Sort 성질때문에 기왕이면 <가 아닌, <=로 작성하는것이 더 좋다.
                resultV.push_back(a.front());
                a.pop_front();
            }
            else {
                resultV.push_back(b.front());
                b.pop_front();
            }
        }
        else if(a.empty()) {
            if(!b.empty()) {
                for(int num : b) resultV.push_back(num);
                break;
            }
            else break;
        }
        else if(b.empty()) {
            if(!a.empty()) {
                for(int num : a) resultV.push_back(num);
                break;
            }
            else break;
        }
    }

    for(int num : resultV) cout << num << " ";


    return 0;
}