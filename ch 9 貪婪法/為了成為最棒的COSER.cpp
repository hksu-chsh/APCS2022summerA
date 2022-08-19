#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].second;
    }
    for(int i=0;i<n;i++){
        cin >> v[i].first;
        v[i].first = v[i].second - v[i].first;
    }
    sort(v.begin(), v.end(), cmp);
    stack<pair<int, int>> stk;
    for(int i=0;i<n;i++){
        if(v[i].first < 0) continue;
        else if(stk.empty()) stk.push(v[i]);
        else{
            if(stk.top().second <= v[i].first) stk.push(v[i]);

        }
    }
    cout << stk.size() << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}