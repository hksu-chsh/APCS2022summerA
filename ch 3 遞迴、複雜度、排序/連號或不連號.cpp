#include<bits/stdc++.h>
using namespace std;
int n;
void solve(){
    priority_queue<int> pq;
    int a, b, t, pre;
    for(int i=0;i<n;i++){
        cin >> t;
        pq.push(t);
    }
    pre = b = pq.top();
    pq.pop();
    bool flag = false;
    while(!pq.empty()){
        a = pq.top();
        if(a != pre - 1){
            flag = true;
        }
        pre = a;
        pq.pop();
    }
    cout << a << " " << b << " " << (flag ? "no\n" : "yes\n");
}
int main(){
	while(cin >> n){
        solve();
	}
}