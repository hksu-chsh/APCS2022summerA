#include<bits/stdc++.h>
using namespace std;
int n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void solve(){
    vector<vector<char>> v(n + 2, vector<char>(m + 2, '*'));
    vector<vector<bool>> vst(n + 2, vector<bool>(m + 2, false));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i][j] == '@' && !vst[i][j]){
                ans++;
                queue<pair<int, int>> que;
                que.push({i, j});
                vst[i][j] = true;
                while(!que.empty()){
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();
                    for(int k=0;k<8;k++){
                        if(v[x+dx[k]][y+dy[k]] == '@' && !vst[x+dx[k]][y+dy[k]]){
                            vst[x+dx[k]][y+dy[k]] = true;
                            que.push({x+dx[k], y+dy[k]});
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    while(cin >> n >> m && (n!=0 && m != 0)){
        solve();
    }
}