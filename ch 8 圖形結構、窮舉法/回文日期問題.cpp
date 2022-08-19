#include<bits/stdc++.h>
using namespace std;
vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeap(int y){
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
bool isPalindrome(int n){
	int m = 0, backup = n;
	while(n != 0){
		m = m * 10 + n % 10;
		n /= 10;
	}
	return backup == m;
}
void solve(){
	int y;
	cin >> y;
	vector<int> ans;
	for(int i=0;i<12;i++){
		for(int j=1;j<=month[i];j++){
			int cur = y;
			if(i < 9){
				cur = cur * 10 + i + 1;
				if(j < 10){
					cur = cur * 10 + j;
					if(isPalindrome(cur)) ans.push_back(cur);
					cur /= 10;
				}
				cur = cur * 100 + j;
				if(isPalindrome(cur)) ans.push_back(cur);
				cur /= 100;
				cur /= 10;
			}
			cur = cur * 100 + i + 1;
			if(j < 10){
				cur = cur * 10 + j;
				if(isPalindrome(cur)) ans.push_back(cur);
				cur /= 10;
			}
			cur = cur * 100 + j;
			if(isPalindrome(cur)) ans.push_back(cur);
			cur /= 100;
			cur /= 100;
		}
		if(i == 1 && isLeap(y)){
			if(isPalindrome(y * 10000 + 229)){
				ans.push_back(y * 10000 + 229);
			}
			if(isPalindrome(y * 1000 + 229)){
				ans.push_back(y * 1000 + 229);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size();
	for(auto i:ans) cout << " " << i;
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	while(n--){
		solve();
	}
}
