#include<bits/stdc++.h>
using namespace std;

int n, dp[101][101], mx;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    mx = 0;
    for (int a = 1; a <= n; a++){
        for (int b = 1; b <= n; b++){
            for (int c = 0; c < a; c++){
                for (int d = 0; d < b; d++){
                    mx = max(mx, dp[a][b] - dp[a][d] + dp[c][d] - dp[c][b]);
                }
            }
        }
    }
    cout << mx << endl;
}