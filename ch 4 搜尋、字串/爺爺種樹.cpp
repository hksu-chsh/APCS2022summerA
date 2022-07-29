#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int main(){
	int n, m, t;
	cin >> n >> m >> t;
	while(t--){
		int stx, sty, edx, edy;
		cin >> stx >> sty >> edx >> edy;
		int rx = abs(stx - edx), ry = abs(sty - edy);
		for(int i=0;i<=max(rx, ry);i++){
			mp[{stx + (rx == 0 ? 0 : i * (edx - stx) / rx), sty + (ry == 0 ? 0 : i * (edy - sty) / ry)}]++;
		}
	}
	cout << mp.size();
}
