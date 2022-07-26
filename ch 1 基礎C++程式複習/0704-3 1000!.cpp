#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(2570);
    v[0] = 1;
    for(int i=0;i<n;i++){
        int carry = 0;
        for(int j = 0;j<v.size();j++){
            v[j] = v[j] * (i + 1) + carry;
            carry = v[j] / 10;
            v[j] %= 10;
        }
    }
	int st = 2569;
    while(v[st--] == 0);
    for(int i=st+1;i>=0;i--){
        cout << v[i];
    }
    cout<<'\n';
}
