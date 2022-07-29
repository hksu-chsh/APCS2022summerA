#include<bits/stdc++.h>
using namespace std;
int main(){
	string input;
	int sum = 0;
	cin>>input;
	for(int i=0;i<input.length();i++){
		if(i % 2 == 0) sum += (input[i] - '0');
		else sum -= (input[i] - '0');
	}
	cout << abs(sum) << endl;
}