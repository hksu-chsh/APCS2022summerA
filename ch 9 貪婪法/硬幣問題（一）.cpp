#include<bits/stdc++.h>
using namespace std;
void solve(){
	int c[4];
	for(auto &i:c){
		cin>>i;
	}
	int total = c[0]+c[1]*5+c[2]*10+c[3]*50;
	int t;
	cin>>t;
	int s = 0;
	if(t/50>=c[3]){
		t -= 50 * c[3];
		s += c[3];
	}
	else{
		s += t / 50;
		t %= 50;
	}
	if(t/10>=c[2]){
		t -= 10 * c[2];
		s += c[2];
	}
	else{
		s += t / 10;
		t %= 10;
	}
	if(t/5>=c[1]){
		t -= 5 * c[1];
		s += c[1];
	}
	else{
		s += t / 5;
		t %= 5;
	}
	if(t>=c[0]){
		t -= c[0];
		s += c[0];
	}
	else{
		s += t;
		t = 0;
	}
	if(t!=0)cout<<-1;
	else cout<<s;
}
int main() {
	solve();
}