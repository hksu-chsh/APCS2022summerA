#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int cnt = 1;
	while(n != 1){
		if(n % 2){
			n = n * 3 + 1;
		}
		else{
			n /= 2;
		}
		cnt++;
	}
	cout << cnt;
}