#include <bits/stdc++.h>
using namespace std;
int main(){
	string x;
	while(getline(cin, x)){
		for (int i=0;i<x.length();i++){
			if (x[i] >= 65 && x[i] <= 90){
				x[i] += 13;
				if (x[i] > 90){
					x[i] -= 26;
				}
			}
			else if (x[i] >= 97 && x[i] <= 122){
				if (x[i] > 109){
					x[i] -= 13;
				}
				else{
					x[i] += 13;
				}
			}
		}
		cout << x << endl;
	}
}
