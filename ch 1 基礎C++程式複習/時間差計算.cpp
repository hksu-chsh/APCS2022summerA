#include<bits/stdc++.h>
using namespace std;
int main(){
    int h1, m1, s1, h2, m2, s2;
    char c;
    cin >> h1 >> c >> m1 >> c >> s1 >> h2 >> c >> m2 >> c >> s2;
    int rs = (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
    if(rs < 0) rs += 86400;
    if(rs / 3600 < 10) cout << 0;
    cout << rs / 3600 << ":";
    if(rs % 3600 / 60 < 10) cout << 0;
    cout << rs % 3600 / 60 << ":";
    if(rs % 3600 % 60 < 10) cout << 0;
    cout << rs % 3600 % 60;
}