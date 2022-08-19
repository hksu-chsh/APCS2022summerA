#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
void solve(){
    int n, s = 0, t;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<int> len(n + 1, -1);
    vector<pair<int, int>> pos(n + 1);
    vector<int> range(n + 1);
    queue<int> que;
    for(int i=0;i<=n;i++){
        cin >> pos[i].x >> pos[i].y >> range[i];
        if(range[i] == 0) t = i;
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int mht = abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
            if(range[i] >= mht) v[i].push_back(j);
            if(range[j] >= mht) v[j].push_back(i);
        }
    }
    que.push(0);
    len[0] = 0;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        if(len[t] != -1) break;
        for(int i=0;i<v[cur].size();i++){
            if(len[v[cur][i]] == -1){
                len[v[cur][i]] = len[cur] + 1;
                que.push(v[cur][i]);
            }
        }
    }
    cout << len[t] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}