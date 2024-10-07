#include <iostream>
#include <algorithm>

using namespace std;

int board[502][502] = { 0, };
int dp[502][502] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            int input;
            cin >> input;
            board[i][j] = input;
        }
    }

    if(n == 1) {
        cout << board[1][1];
        return 0;
    }

    dp[1][1] = board[1][1];

    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(j == 1) dp[i][j] = dp[i-1][j] + board[i][j];
            else if(j == i) dp[i][j] = dp[i-1][i-1] + board[i][j];
            else {
                int a = dp[i-1][j-1] + board[i][j];
                int b = dp[i-1][j] + board[i][j];
                dp[i][j] = max(a, b);
            }
        }
    }

    int answer = *max_element(&dp[n][1], &dp[n][n+1]);
    cout << answer;


    return 0;
}