#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int maxA = -1, maxB = -1;
    for(auto v : sizes) {
        int a = min(v[0], v[1]);
        int b = max(v[0], v[1]);
        
        maxA = max(maxA, a);
        maxB = max(maxB, b);
    }
    
    return maxA*maxB;
}

int main()
{
    vector<vector<int>> sizes1 = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};
    vector<vector<int>> sizes2 = {{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}};
    vector<vector<int>> sizes3 = {{14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11}};

    int answer1 = solution(sizes1);
    int answer2 = solution(sizes2);
    int answer3 = solution(sizes3);

    cout << answer1 << "\n";  // => 4000 출력
    cout << answer2 << "\n";  // => 120 출력
    cout << answer3 << "\n";  // => 133 출력


    return 0;
}