#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// - 문제풀이 방식 도출 과정:
// 과정 1. 치킨집들중 폐업시키지않을 치킨집 M개를 골라야함 => 조합을 의미.
// 과정 2. 해당 고른 경우에서의 도시의 치킨거리들을 모두 구해보기 (즉, 각 모든집에 모든치킨을 좌표 대응하여 가능한 거리를 모두 계산) => 브루트 포스 사용.
//        브루트 포스 중에서 백트래킹을 사용하여 거리들을 모두 구해볼수도 있겠지만, 이 문제의 경우는 굳이 백트래킹없이 2중 for(auto)문을 사용하면 더 쉽게 구할 수 있음.
//        참고로 치킨거리값 계산은 어차피 문제에서 명시한 좌표값빼기 방식으로 구하면 되므로, BFS는 사용하지않아도됨.
// 과정 3. 하지만 코드 최적화를 위해서, 조합의 do~while문 안에서 치킨값 거리계산까지 실시하는것이 좋다.
// 과정 4. 구한 치킨거리들중 최솟값을 출력하기

int n,m;

vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
vector<int> temp;

vector<int> allSumDist;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int input;
            cin >> input;

            if(input == 2) {
                chicken.push_back({i,j});
                temp.push_back(1);
            }
            else if(input == 1) {
                house.push_back({i,j});
            }
        }
    }
    fill(temp.begin(), temp.begin()+m, 0);

    do {  // 치킨집 고르기 => 조합
        vector<pair<int,int>> select;
        for(int i=0; i<chicken.size(); i++) {
            if(temp[i] == 0)
                select.push_back(chicken[i]);
        }

        int sumDist = 0;
        for(auto hP : house) {
            int minDist = 1e9;
            for(auto cP : select) {
                int dist = abs(hP.first - cP.first) + abs(hP.second - cP.second);
                minDist = min(minDist, dist);
            }
            sumDist += minDist;
        }
        allSumDist.push_back(sumDist);
    } while(next_permutation(temp.begin(), temp.end()));

    cout << *min_element(allSumDist.begin(), allSumDist.end());


    return 0;
}