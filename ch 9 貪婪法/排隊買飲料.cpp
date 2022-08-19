#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		pq.push(0);
	}
	while(n--){
		int t;
		cin >> t;
		pq.push(pq.top() + t);
		pq.pop();
	}
	while(pq.size() > 1){
		pq.pop();
	}
	cout << pq.top();
}