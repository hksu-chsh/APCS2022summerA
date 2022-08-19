#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, t = 1;
	while(cin >> n >> m && n + m != 0){
        cout << "Twin Towers #" << t << endl;
        t++;
        vector<int> v1(n), v2(m);
        for(auto &i:v1) cin >> i;
        for(auto &i:v2) cin >> i;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = v1[0] == v2[0];
        for(int i=1;i<n;i++){
            dp[i][0] = v1[i] == v2[0] ? 1 : dp[i-1][0];
        }
        for(int i=1;i<m;i++){
            dp[0][i] = v2[i] == v1[0] ? 1 : dp[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = v1[i] == v2[j] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << "Number of Tiles : " << dp.back().back() << endl << endl;
	}
}