#include<bits/stdc++.h>
using namespace std;
long long t = 0;
void hanoi(char x,char y,char z,int n){
	if(n == 1){
		cout << "ring 1 : " << x << " => " << z << "\n";
		t++;
	}
	if(n > 1){
		hanoi(x, z, y, n - 1);
		cout << "ring " << n << " : " << x << " => " << z << "\n";
		t++;
		hanoi(y, x, z, n - 1);
	}
}
void hanoi3(char position,int n){
	if(n != 0){
		if(position == 'A'){
			hanoi('A', 'C', 'B', n - 3);
			cout << "ring " << n - 2 << " : A => C\n";
			hanoi('B', 'A', 'C', n - 3);
			cout << "ring " << n - 1 << " : A => B\n";
			hanoi('C', 'B',' A', n - 3);
			cout << "ring " << n - 2 << " : C => B\n";
			hanoi('A', 'C', 'B', n - 3);
			cout << "ring " << n << " : A => C\n";
			hanoi('B', 'A', 'C', n - 3);
			cout << "ring " << n - 2 << " : B => A\n";
			t += 5;
			hanoi3('C', n - 3);
		}
		if(position == 'C'){
			hanoi('C', 'A', 'B', n - 3);
			cout << "ring " << n - 2 << " : C => A\n";
			hanoi('B', 'C', 'A', n - 3);
			cout << "ring " << n - 1 << " : C => B\n";
			t += 2;
			hanoi3('A', n - 3);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	int num;
	cin >> num;
	hanoi3('A', num);
	cout << "共需" << t << "個移動\n";
}
