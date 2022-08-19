#include<bits/stdc++.h>
using namespace std;
int main(){
	int N, M;
	cin>>N>>M;
	int graph[N][N] = {0};
	for(int i=0;i<M;i++){
		int a, b;
		cin>>a>>b;
		graph[a][b] = 1;
	}
	int from, to;
	cin>>from>>to;
	queue<int> que;
	bool visited[N] = {false};
	que.push(from);
	visited[from] = true;
	while(!que.empty()){
		int nxt = que.front();
		que.pop();
		if(nxt == to)break;
		for(int i=0;i<N;i++){
			if(graph[nxt][i]==1 && !visited[i]){
				que.push(i);
				visited[i] = true;
			}
		}
	}
	cout<<(visited[to]?"YES":"NO");
	return 0;
}