#include<bits/stdc++.h>
#define WIDTH 8
using namespace std;
vector<vector<int>> v(WIDTH, vector<int>(WIDTH));
vector<int> queen(WIDTH, -1);
int result = 0;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
void backtracking(int cur, vector<vector<int>> mp){	// cur: 現在正在放第幾個皇后
	/*for(auto i:mp){
		for(auto j:i){
			cout << j << '\t';
		}cout << endl;
	}cout << endl;*/
	// queen[x]: 代表在第 x 橫行的第 queen[x] 個有皇后
	if(cur == WIDTH){
		int ans = 0;
		for(int i=0;i<WIDTH;i++){
			ans += v[i][queen[i]];
		}
		result = max(result, ans);
		return;
	}
	for(int i=0;i<WIDTH;i++){//cout << cur << " " << i << endl;
		if(mp[cur][i] == 0){	// still safe
			mp[cur][i] = 1;	// 放皇后
			for(int j=1;j<WIDTH;j++){
				for(int k=0;k<8;k++){
					int cx = cur + dx[k] * j;
					int cy = i + dy[k] * j;
					if(cx < 0 || cy < 0 || cx > WIDTH - 1 || cy > WIDTH - 1) continue;
					mp[cx][cy]++;
				}
			}
			queen[cur] = i;
			backtracking(cur + 1, mp);
			for(int j=1;j<WIDTH;j++){
				for(int k=0;k<8;k++){
					int cx = cur + dx[k] * j;
					int cy = i + dy[k] * j;
					if(cx < 0 || cy < 0 || cx > WIDTH - 1 || cy > WIDTH - 1) continue;
					mp[cx][cy]--;
				}
			}
			mp[cur][i] = 0;
		}
	}
}
void solve(){
	for(auto &i:v){
		for(auto &j:i){
			cin >> j;
		}
	}
	vector<vector<int>> mp(WIDTH, vector<int>(WIDTH));	// 0: safe ; 1 以上: danger
	backtracking(0, mp);
	cout << result << endl;
	result = 0;
}
int main(){
	int n;
	cin >> n;
	while(n--){
		solve();
	}
}