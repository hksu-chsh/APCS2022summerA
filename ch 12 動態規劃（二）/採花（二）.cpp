#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int arr[n];
    int sum = 0;
    for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
    }
    bitset<100005> B;
    B[0] = 1;
    for(int i:arr){
		B |= (B<<i);
    }
    while(B[m]==0)m--;
    cout<<m;
	return 0;
}