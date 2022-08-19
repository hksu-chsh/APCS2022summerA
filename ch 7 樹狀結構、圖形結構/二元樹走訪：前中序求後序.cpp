#include<bits/stdc++.h>
using namespace std;
int n;
int *in;
int *pre;
void make_postorder(int preL, int preR, int inL, int inR){
	int root = pre[preL];
	if(inL > inR || preL > preR)return;
	int rtidx;
	for(int i=inL;i<=inR;i++){
		if(in[i]==root){
			rtidx = i;
			break;
		}
	}
	int ll = rtidx - inL;
	make_postorder(preL + 1, preL + ll, inL, rtidx - 1);	// left
	make_postorder(preL + ll + 1, preR, rtidx + 1, inR);	// right
	cout<<root<<" ";
}
int main(){
	cin>>n;
	in = new int[n];
	pre = new int[n];
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	make_postorder(0, n-1, 0, n-1);
}
