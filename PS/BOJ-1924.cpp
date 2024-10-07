#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x,y;
    cin >> x >> y;

    vector<int> monthV = { 0,0,31,28,31,30,31,30,31,31,30,31,30,31 };
    auto iter = monthV.begin() + x;
    int month = accumulate(monthV.begin(), iter+1, 0);
    int daySum = month + y;
    daySum %= 7;

    vector<string> resultV = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    cout << resultV[daySum];


    return 0;
}