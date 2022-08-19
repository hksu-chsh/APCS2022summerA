#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
double dist(pair<long long, long long> a, pair<long long, long long> b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double min_distance(vector<pair<long long, long long>> v, long long st, long long ed){
	if(st >= ed) return 45000;
	if(st == ed - 1) return dist(v[st], v[ed]);
	long long mid = (st + ed) / 2;
	double dL = min_distance(v, st, mid - 1);
	double dR = min_distance(v, mid + 1, ed);
	double ans = min(dL, dR);
	int l = mid - 1, r = mid + 1;
	while(l >= st){
		if(v[mid].x - v[l].x > ans){
			break;
		}
		l--;
	}
	while(r <= ed){
		if(v[r].x - v[mid].x > ans){
			break;
		}
		r++;
	}
	for(int i=l+1;i<r;i++){
		for(int j=i+1;j<r;j++){
			ans = min(ans, dist(v[i], v[j]));
		}
	}
	return ans;
}
void solve(int n){
	vector<pair<long long, long long>> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end());
	double ans = min_distance(v, 0, n - 1);
	if(ans > 10000) cout << "INFINITY\n";
	else cout << fixed << setprecision(4) << ans << endl;
}
int main(){
	int n;
	while(cin >> n && n != 0){
		solve(n);
	}
}