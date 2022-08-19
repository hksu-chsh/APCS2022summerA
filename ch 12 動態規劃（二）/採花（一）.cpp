#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
		cin >> arr[i];
    }
    int dp[n] = {0};
    for(int i=0;i<n;i++){
		dp[i] = arr[i];
		for(int j=0;j<i;j++){
			if(dp[j] + arr[i] > dp[i] && arr[i] > arr[j])
				dp[i] = dp[j] + arr[i];
		}
    }
    cout << *max_element(dp, dp + n);
}