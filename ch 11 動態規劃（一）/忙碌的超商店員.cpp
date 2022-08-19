#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int v[6] = {1, 5, 10, 12, 16, 20};
	vector<int> dp(n + 1);
	for(int i=0;i<6;i++){
		int coins = v[i];
		for(int j=coins;j<=n;j++){
			if(coins == 1) dp[j] = j;
			else dp[j] = min(dp[j], dp[j - coins] + 1);
		}
	}
	cout << dp.back();
}