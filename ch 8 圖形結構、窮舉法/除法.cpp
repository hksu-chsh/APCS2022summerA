#include<bits/stdc++.h>
using namespace std;
void solve(int n){
	int ans = 0;
	int mask = 0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				for(int l=0;l<10;l++){
					for(int m=0;m<10;m++){
						mask = (1 << i);
						mask |= (1 << j);
						mask |= (1 << k);
						mask |= (1 << l);
						mask |= (1 << m);
						int fghij = i * 10000 + j * 1000 + k * 100 + l * 10 + m;
						int abcde = fghij * n;
						int backup = abcde;
						for(int a=0;a<5;a++){
							mask |= (1 << (abcde % 10));
							abcde /= 10;
						}
						if(mask == ((1 << 10) - 1) && abcde == 0){
							cout << backup << " / " << i << j << k << l << m << " = " << n << endl;
							ans++;
						}
					}
				}
			}
		}
	}
	if(ans == 0) cout << "There are no solutions for " << n << ".\n";
	cout << endl;
}
int main(){
	int n;
	while(cin >> n && n != 0){
		solve(n);
	}
}
