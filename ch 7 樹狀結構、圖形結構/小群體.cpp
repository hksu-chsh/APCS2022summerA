#include<bits/stdc++.h>
using namespace std;
vector<int> best_friend;
vector<int> visited;
void traversal(int x){
    if(visited[x] == 0){
        visited[x] = 1;
        traversal(best_friend[x]);
    }
}
int main(){
	int n;
	cin >> n;
	best_friend.resize(n);
	visited.resize(n);
	for(int i=0;i<n;i++){
        cin >> best_friend[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++){
        if(visited[i] == 0){
            ans++;
            traversal(i);
        }
	}
	cout << ans << endl;
}