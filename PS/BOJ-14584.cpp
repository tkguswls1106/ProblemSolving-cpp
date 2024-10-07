#include <string>
#include <vector>
#include <iostream>

using namespace std;

void pushEng(char& ch) {
    if(ch == 'z') ch = 'a';
    else ch += 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    int n;
    cin >> str >> n;
    vector<string> v;
    while(n--) {
        string input;
        cin >> input;
        v.push_back(input);
    }

    while(true) {
        bool whileEnd = false;
        for(string findStr : v) {
            if(str.find(findStr) != string::npos) whileEnd = true;
        }
        if(whileEnd) break;

        for(char& ch : str) {
            pushEng(ch);
        }
    }

    cout << str;


    return 0;
}