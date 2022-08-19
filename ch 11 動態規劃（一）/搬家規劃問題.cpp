#include<bits/stdc++.h>
using namespace std;
stringstream ss, sss;
string s1, s2;
int iter, w[1005], v[1005], a[1000005], n;
int main() {
    getline(cin, s1);
    ss << s1;
    iter = 0;
    while (ss >> s1){
        w[iter] = stoi(s1);
        iter++;
    }
    getline(cin, s2);
    sss << s2;
    iter = 0;
    while (sss >> s2){
        v[iter] = stoi(s2);
        iter++;
    }
    cin >> n;
    for (int i = 0; i < iter; i++){
        for (int j = n; j > 0; j--){
            if (j - w[i] >= 0) a[j] = max(a[j], a[j-w[i]]+v[i]);
        }
    }
    cout << a[n] << "\n";
}