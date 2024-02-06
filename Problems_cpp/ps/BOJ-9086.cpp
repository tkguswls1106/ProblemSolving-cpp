#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    string input;
    cin >> t;
    while(t--) {
        cin >> input;
        string str = "";
        str += input[0];
        str += input[input.size()-1];

        cout << str << "\n";
    }


    return 0;
}