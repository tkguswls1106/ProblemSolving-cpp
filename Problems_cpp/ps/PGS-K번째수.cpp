#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto v : commands) {
        vector<int> v2(array.begin()-1+v[0], array.begin()-1+v[1]+1);
        sort(v2.begin(), v2.end());

        answer.push_back(v2[v[2]-1]);
    }
    
    return answer;
}

int main()
{
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

    vector<int> answer = solution(array, commands);

    for(int num : answer) cout << num << " ";  // => 5 6 3 출력


    return 0;
}