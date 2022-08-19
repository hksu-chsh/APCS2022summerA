#include<bits/stdc++.h>
using namespace std;
int n;
int *in;
int *post;
void make_preorder(int inL, int inR, int postL, int postR){
	int root = post[postR];
	if(inL > inR || postL > postR)return;
	int rtidx;
	for(int i=inL;i<=inR;i++){
		if(in[i]==root){
			rtidx = i;
			break;
		}
	}
	int length = rtidx - inL;
	cout<<root<<" ";
	make_preorder(inL, rtidx - 1, postL, postL + length - 1);	// left
	make_preorder(rtidx + 1, inR, postL + length, postR - 1);	// right
}
int main(){
	cin>>n;
	in = new int[n];
	post = new int[n];
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	for(int i=0;i<n;i++){
		cin>>post[i];
	}
	make_preorder(0, n-1, 0, n-1);
}
