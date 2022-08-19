#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> height, len;
void DFS(int x){
	// x 節點的高度
	// 以 x 節點為根所經過的最長血緣距離
	if(v[x].size() == 0){
		// 這是一片葉子
		height[x] = 0;
		len[x] = 1;
		return;
	}
	int First = 0, Second = 0;	// x 節點之中，最高跟第二高的小孩的高度
	for(int i=0;i<v[x].size();i++){
		DFS(v[x][i]);
		if(height[v[x][i]] > Second){
			Second = height[v[x][i]];
		}
		if(First < Second){
			swap(First, Second);
		}
	}
	height[x] = First + 1;
	if(v[x].size() >= 2){
		len[x] = First + Second + 2;
	}
	else{
		len[x] = First + 1;
	}
}
int main(){
    int n;
    cin >> n;
    v.resize(n);
    height.resize(n);
    len.resize(n);
    vector<bool> isChild(n);
    for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		isChild[b] = true;
    }
    int root;
    for(int i=0;i<n;i++){
		if(!isChild[i]){
			root = i;
			break;
		}
    }
    DFS(root);
	cout << *max_element(len.begin(), len.end()) << endl;
}