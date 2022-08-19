#include<bits/stdc++.h>
#define W first
#define F second
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
	return a.W * b.F < a.F * b.W;
	// a 在上   a 在下
}
int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].W;
	}
	for(int i=0;i<n;i++){
		cin >> v[i].F;
	}
	long long ans = 0;
	sort(v.begin(), v.end(), cmp);
	// v[0] 疊在最上方
	long long current_weight = v[0].W;
	for(int i=1;i<n;i++){
		ans += v[i].F * current_weight;
		current_weight += v[i].W;
	}
	cout << ans << endl;
}