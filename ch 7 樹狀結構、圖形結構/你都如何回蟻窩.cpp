#include<bits/stdc++.h>
using namespace std;
vector<int> A, B;
vector<vector<int>> pos;
void postorder(int pl, int pr, int il, int ir){
	if(pl > pr || il > ir) return;
	int root = A[pl];
	int lc = pos[root][0] - il, mc = pos[root][1] - pos[root][0] - 1, rc = ir - pos[root][1];
	lc /= 2; mc /= 2; rc /= 2;
	if(lc > 0)
		postorder(pl + 1, pl + lc, il, pos[root][0] - 1);
	if(mc > 0)
		postorder(pl + lc + 1, pr - rc, pos[root][0] + 1, pos[root][1] - 1);
	if(rc > 0)
		postorder(pr - rc + 1, pr, pos[root][1] + 1, ir);
	cout << root;
	if(root != A[0]) cout << " ";
}
int main(){
	ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	A.resize(n);
	B.resize(2 * n);
	pos.resize(n + 1);

	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n*2;i++){
		cin >> B[i];
		pos[B[i]].push_back(i);
	}
	postorder(0, n - 1, 0, 2 * n - 1);
}