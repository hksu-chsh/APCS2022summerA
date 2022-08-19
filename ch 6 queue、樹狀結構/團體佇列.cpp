#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int cnt = 1;
    while(cin >> t && t != 0){
        cout << "Scenario #" << cnt << endl;
        cnt++;
        queue<pair<queue<int>, int>> que;
        vector<vector<int>> v(t);
        for(int i=0;i<t;i++){
            int n;
            cin >> n;
            v[i].resize(n);
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }
        }
        string cmd;
        while(cin >> cmd && cmd != "STOP"){
            if(cmd == "ENQUEUE"){
                int n;
                cin >> n;
                int group = -1;
                for(int i=0;i<t;i++){
                    for(int j=0;j<v[i].size(); j++){
                        if(v[i][j] == n){
                            group = i;
                            break;
                        }
                    }
                    if(group != -1){
                        break;
                    }
                }
                bool gp = false;
                for(int i=0;i<que.size();i++){
                    if(que.front().second == group){
                        gp = true;
                        que.front().first.push(n);
                    }
                    que.push(que.front());
                    que.pop();
                }
                if(!gp){
                    queue<int> q;
                    q.push(n);
                    que.push({q, group});
                }
            }
            else if(cmd == "DEQUEUE"){
                cout << que.front().first.front() << endl;
                que.front().first.pop();
                if(que.front().first.empty()){
                    que.pop();
                }
            }
        }
    }
}
