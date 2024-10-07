#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    
    int smallX = 99, bigX = -1, smallY = 99, bigY = -1;
    for(int i=0; i<wallpaper.size(); i++) {
        for(int j=0; j<wallpaper[0].size(); j++) {
            if(wallpaper[i][j] != '#') continue;
            smallX = min(smallX, i);
            smallY = min(smallY, j);
            bigX = max(bigX, i);
            bigY = max(bigY, j);
        }
    }
    
    return {smallX, smallY, bigX+1, bigY+1};
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}