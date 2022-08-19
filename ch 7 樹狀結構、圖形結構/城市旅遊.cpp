#include<bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<int, vector<int>> route;
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        route[x].push_back(y);
    }
    int A, B;
    cin >> A >> B;
    vector<bool> v(n, false);
    queue<int> que;
    que.push(A);
    v[A] = true;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto i:route[cur]){
            if(!v[i]){
                que.push(i);
                v[i] = true;
            }
        }
    }
    cout << (v[B] ? "Yes" : "No") << endl;
}