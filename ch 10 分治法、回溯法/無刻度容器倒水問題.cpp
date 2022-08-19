#include<bits/stdc++.h>
using namespace std;
struct bottle{
	int a = 0, b = 0, times = 0;
};
int main(){
	int n;
	cin >> n;
	while(n--){
		map<pair<int, int>, bool> m;
		int x, y, z;
		cin >> x >> y >> z;
		int ans = -1;
		queue<bottle> que;
		que.push({0, 0, 0});
		while(!que.empty()){
			bottle cur = que.front();
			que.pop();
			if(m[{cur.a, cur.b}]) continue;
			m[{cur.a, cur.b}] = true;
			if(cur.a == z || cur.b == z){
				ans = cur.times;
				break;
			}
			if(cur.a < x){	// 加滿 a
				que.push({x, cur.b, cur.times + 1});
			}
			if(cur.a > 0){	// 倒掉 a
				que.push({0, cur.b, cur.times + 1});
			}
			if(cur.b < y){	// 加滿 b
				que.push({cur.a, y, cur.times + 1});
			}
			if(cur.b > 0){	// 倒掉 b
				que.push({cur.a, 0, cur.times + 1});
			}
			if(cur.a > 0 && cur.b < y){	// a -> b
				que.push({max(0, cur.a - y + cur.b), min(y, cur.b + cur.a), cur.times + 1});
			}
			if(cur.a < x && cur.b > 0){	// b -> a
				que.push({min(x, cur.b + cur.a), max(0, cur.b - x + cur.a), cur.times + 1});
			}
		}
		cout << ans << endl;
	}
}