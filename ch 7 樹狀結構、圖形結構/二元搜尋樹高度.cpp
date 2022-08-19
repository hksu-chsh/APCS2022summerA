#include<bits/stdc++.h>
using namespace std;
vector<int> v(2048, INT_MIN);
int put(int n, int pos){
    if(v[pos] == INT_MIN){
        v[pos] = n;
        return 1;
    }
    if(v[pos] > n){
        return put(n, pos * 2 + 1) + 1;
    }
    else return put(n, pos * 2 + 2) + 1;
}
int main(){
	int n, max_h = 0;
	while(cin >> n){
        max_h = max(max_h, put(n, 0));
	}
	cout << max_h << endl;
}