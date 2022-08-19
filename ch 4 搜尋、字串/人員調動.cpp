#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<pair<int, int>, int> m;
    int n, ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        m[{a, b}]++;
    }
    for(auto &i:m){
        int a = i.first.first, b = i.first.second;
        if(m[{a, b}] > 0 &&  m[{b, a}] > 0 && a != b){
            ans += min(m[{a, b}], m[{b, a}]);
            m[{a, b}] = m[{b, a}] = 0;
        }
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
    solve();
    }
}
