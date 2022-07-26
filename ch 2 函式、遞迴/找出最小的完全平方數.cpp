#include<bits/stdc++.h>
using namespace std;
bool check(int num){
    while(num % 2 == 0){
        num /= 10;
        if(num == 0){
            return true;
        }
    }
    return false;
}
int main(){
	int n, k;
	cin >> n;
	for(int i=0;i<n;i++){
        cin >> k;
        for(int j=sqrt(pow(10, k-1));j<=sqrt(pow(10, k));j++){
            if(check(j * j)){
                cout << j * j << endl;
                break;
            }
        }
	}
}