#include<bits/stdc++.h>
using namespace std;
int main(){
	int x, y;
	cin >> x >> y;
	vector<vector<long long>> dp(33, vector<long long>(33));
	for(int i=0;i<=32;i++){
		dp[i][0] = dp[0][i] = 1;
	}
	for(int i=1;i<=32;i++){
		for(int j=1;j<=32;j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[x][y];
}