#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int mon = nums.size()/2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    if(nums.size() >= mon) return mon;
    else return nums.size();
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}