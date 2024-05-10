#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int t = bandage[0];  // 시전 시간
    int plus = bandage[1];  // 1초당 회복량
    int plus2 = bandage[2];  // 추가 회복량

    unordered_map<int, int> m;
    for(int i=0; i<attacks.size(); i++) {
        int attackTime = attacks[i][0];
        int minus = attacks[i][1];
        m[attackTime] = minus;
    }
    
    int lastTime = attacks.back().front();
    int nowHealth = health;
    int successCnt = 0;
    for(int i=1; i<=lastTime; i++) {
        if(m.count(i) == 0) {  // 회복 가능할때 (공격 X)
            successCnt++;
            nowHealth += plus;  // 회복
            
            if(successCnt == t) {  // 추가회복
                successCnt = 0;
                nowHealth += plus2;
            }
            if(nowHealth > health) nowHealth = health;  // 초과 회복한 경우
        }
        else {  // 회복 불가능할때 (공격 O)
            successCnt = 0;
            nowHealth -= m[i];  // 피해받음
            
            if(nowHealth <= 0) return -1;  // 죽는 경우
        }
    }
    
    return nowHealth;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}