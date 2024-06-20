#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    int size;
    string str;
    for(int i=1; i<phone_book.size(); i++) {
        size = phone_book[i-1].size();
        str = phone_book[i].substr(0,size);
        if(phone_book[i-1] == str) return false;
    }
    
    return true;
}

int main()
{
    // 메인함수 코드 생략
    return 0;
}