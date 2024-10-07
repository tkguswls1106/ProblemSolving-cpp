#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[31] = { 0, };
    
    for(int i=0; i<lost.size(); i++) student[lost[i]]--;
    for(int i=0; i<reserve.size(); i++) student[reserve[i]]++;
    
    for(int i=1; i<=n; i++){
        if(student[i] == -1){  // 해당 학생이 도난당했을때
            if(student[i-1] == 1){  // 그 앞사람이 여벌 보유 (1이면 추가여벌 보유한것임)
                student[i-1] = 0;
                student[i] = 0;
            }
            else if(student[i+1] == 1){  // 그 뒷사람이 여벌 보유 (1이면 추가여벌 보유한것임)
                student[i+1] = 0;
                student[i] = 0;
            }
        }   

        if(student[i] >= 0) answer++;
    }
    
    return answer;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}