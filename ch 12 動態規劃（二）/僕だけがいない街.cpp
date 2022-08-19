#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, t, ans=0;
    cin >> n;
    while(n--){
        cin >> t;
        ans ^= t;
        ans ^= n + 1;
    }
    cout << ans;
}