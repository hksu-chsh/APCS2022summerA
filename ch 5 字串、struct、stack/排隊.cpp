#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    queue<pair<int, int>> que;
    int cur = 1, nxt = v[0].first + v[0].second;
    int ans = 0;
    while(cur < n){
        if(v[cur].first < nxt){
            que.push(v[cur]);
            cur++;
        }
        else{
            if(que.empty()){
                nxt = v[cur].first + v[cur].second;
                cur++;
            }
            else{
                nxt = max(nxt, que.front().first) + que.front().second;
                que.pop();
            }
        }
        ans = max((int)que.size(), ans);
    }
    cout << ans;
}
