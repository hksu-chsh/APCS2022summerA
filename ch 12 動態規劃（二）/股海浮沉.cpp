#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, ans = 0;
	cin >> n;
	vector<int> v(n), dp(n);
	for(auto &i:v) cin >> i;
	dp[0] = max(0, v[0]);
	for(int i=1;i<n;i++){
		dp[i] = max(v[i], dp[i - 1] + v[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}