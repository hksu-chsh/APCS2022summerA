#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int &i : arr) cin >> i;
    sort(arr, arr + n);
    for(int i=0;i<n;i++) cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    int e = lower_bound(arr, arr + n, 60) - arr;
    if(e == 0) cout << "best case\n"; else cout << arr[e - 1] << endl;
    if(e == n) cout << "worst case"; else cout << arr[e];
}