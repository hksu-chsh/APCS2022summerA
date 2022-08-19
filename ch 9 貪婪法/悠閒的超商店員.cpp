#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, coin[9] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000}, ans = 0;
	cin >> n;
	for(int i=8;i>=0;i--){
	while(n >= coin[i]){
		n -= coin[i];
		ans++;
		}
	}
	cout << ans << endl;
}