#include<bits/stdc++.h>
using namespace std;
int a[75];
void power(int b){
    for (int i = 0; i < b; i++){
        int carry = 0;
        for (int j = 0; j < 75; j++){
            a[j] = a[j] * 4 + carry;
            carry = a[j] / 10;
            a[j] = a[j] % 10;
        }
    }
}
void divide(int b){
    int carry = 0;
    for (int i = 74; i >= 0; i--){
        a[i] += carry * 10;
        carry = a[i] % b;
        a[i] = a[i] / b;
    }
}
int main(){
    int n;
    cin >> n;
    a[0] = 1;
    power(n);
    a[0] -= 1;
    divide(3);
    bool flag = false;
    for (int i = 74; i >= 0; i--){
        if (a[i] == 0 && !flag) continue;
        flag = true;
        cout << a[i];
    }
}