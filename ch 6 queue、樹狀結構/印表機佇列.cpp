#include<bits/stdc++.h>
using namespace std;
void solve(){
	vector<int> v(10), prefix(10);
	queue<pair<int, int>> que;
	int n, m, lv, p = 0, ans = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int s;
		cin >> s;
		que.push({s, i});
		v[s]++;
		if(i == m) lv = s;
	}
	for(int i=8;i>0;i--){
		prefix[i] += v[i + 1] + prefix[i + 1];
	}
	while(!que.empty()){
		int cur_lv = que.front().first, cur_n = que.front().second;
		if(cur_lv > lv){
			if(prefix[cur_lv] - ans > 0){
				que.push(que.front());
				que.pop();
			}
			else{
				que.pop();
				ans++;
			}
		}
		else if(cur_lv == lv){
			if(prefix[cur_lv] - ans <= 0){
				if(cur_n != m){
					ans++;
					que.pop();
				}
				else{
					ans++;
					break;
				}
			}
			else{
				que.push(que.front());
				que.pop();
			}
		}
		else{
			que.push(que.front());
			que.pop();
		}
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}