#include<bits/stdc++.h>
using namespace std;
queue<string> que;
int calc(){
	string t = que.front();
	que.pop();
	if(t == "+"){
		return calc() + calc();
	}
	else if(t == "-"){
		return calc() - calc();
	}
	else if(t == "*"){
		return calc() * calc();
	}
	else if(t == "/"){
		return calc() / calc();
	}
	else if(t == "%"){
		return calc() % calc();
	}
	else{
		stringstream ss;
		ss<<t;
		int r;
		ss>>r;
		return r;
	}
}
int main(){
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		que.push(s);
	}
	cout<<calc();

	return 0;
}