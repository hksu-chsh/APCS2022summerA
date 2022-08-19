#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	int p2[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
	while(t--){
        int n, m;
        cin >> n >> m;
        int mx = p2[n];
        bool tree[mx] = {};
        int cur = 1;
        for(int i=0;i<m;i++){
            cur = 1;
            while(cur < p2[n - 1]){
                tree[cur] = !tree[cur];
                cur = cur * 2 + 1 - tree[cur];
            }
        }
        cout << cur << endl;
	}
}