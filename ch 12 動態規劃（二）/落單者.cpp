#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t, result = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        result ^= t;
    }
    cout << result;
}