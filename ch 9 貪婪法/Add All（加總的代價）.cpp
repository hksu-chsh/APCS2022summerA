#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin >> n && n != 0){
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for(int i=0;i<n;i++){
			long long t;
			cin >> t;
			pq.push(t);
		}
		long long ans = 0;
		while(pq.size() > 1){
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			pq.push(a + b);
			ans += a + b;
		}
		cout << ans << endl;
	}
}