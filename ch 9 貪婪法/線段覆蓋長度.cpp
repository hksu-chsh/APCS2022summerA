#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, -1});
		v.push_back({b, 1});
	}
	sort(v.begin(), v.end());
	int ans = 0;
	stack<pair<int, int>> stk;
	for(int i=0;i<v.size();i++){
		if(v[i].second == -1){
			stk.push(v[i]);
		}
		else{
			if(stk.size() == 1){
				ans += v[i].first - stk.top().first;
			}
			stk.pop();
		}
	}
	cout << ans << endl;
}