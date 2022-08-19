#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b){
	if(b==0)return a;
	return GCD(b, a%b);
}
void solve(){
	int n, m, res = 0;
	cin>>n>>m;
	vector<vector<int>> v;
	vector<vector<bool>> visited;
	v.resize(n+2);
	visited.resize(n+2);
	for(auto &i:v){
		i.resize(m+2);
		for(auto &j:i){
			j = 1;
		}
	}
	for(auto &i:visited){
		i.resize(m+2);
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			cin>>v[i][j];
		}
	}
	int s, t;
	bool flag = false;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(!visited[i][j]){
				s = i;
				t = j;
				flag = true;
				break;
			}
		}
	}
	while(flag){
		res++;
		visited[s][t] = true;
		queue<pair<int, int>> que;
		que.push({s, t});
		int res = 1;
		visited[s][t] = true;
		while(!que.empty()){
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			if(!visited[x-1][y]){
				if(GCD(v[x][y], v[x-1][y])!=1){
					que.push({x-1, y});
					res++;
					visited[x-1][y] = true;
				}
			}
			if(!visited[x+1][y]){
				if(GCD(v[x][y], v[x+1][y])!=1){
					que.push({x+1, y});
					res++;
					visited[x+1][y] = true;
				}
			}
			if(!visited[x][y-1]){
				if(GCD(v[x][y], v[x][y-1])!=1){
					que.push({x, y-1});
					res++;
					visited[x][y-1] = true;
				}
			}
			if(!visited[x][y+1]){
				if(GCD(v[x][y], v[x][y+1])!=1){
					que.push({x, y+1});
					res++;
					visited[x][y+1] = true;
				}
			}
		}
		flag = false;
		for(int i=1;i<n+1;i++){
			for(int j=1;j<m+1;j++){
				if(!visited[i][j]){
					s = i;
					t = j;
					flag = true;
					break;
				}
			}
		}
	}
	cout<<res<<endl;
}
int main(){
	solve();
}
