#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int getDist(string origin, string goal) {
    char x1 = origin[0], y1 = origin[1], x2 = goal[0], y2 = goal[1];
    return abs(x1-x2) + abs(y1-y2);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int board[4][3] = {1,2,3,4,5,6,7,8,9,11,0,99};
    unordered_map<int, string> m;
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            string str = to_string(i) + to_string(j);
            m[board[i][j]] = str;
        }
    }

    string left = "30", right = "32";
    for(int num : numbers) {
        if(num == 1 || num == 4 || num == 7) {
            answer += 'L';
            left = m[num];
        }
        else if(num == 3 || num == 6 || num == 9) {
            answer += 'R';
            right = m[num];
        }
        else {
            int lDist = getDist(left, m[num]), rDist = getDist(right, m[num]);
            if(lDist < rDist) {
                answer += 'L';
                left = m[num];
            }
            else if(lDist > rDist) {
                answer += 'R';
                right = m[num];
            }
            else {
                if(hand == "left") {
                    answer += 'L';
                    left = m[num];
                }
                else {
                    answer += 'R';
                    right = m[num];
                }
            }
        }
    }
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}