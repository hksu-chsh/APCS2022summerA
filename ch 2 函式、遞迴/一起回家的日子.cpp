#include <bits/stdc++.h>
using namespace std;
inline bool is_leap(int y) {
	if (y % 4 == 0 && y % 100 != 0) {
		return true;
	}
	if (y % 400 == 0) {
		return true;
	}
	return false;
}

inline int days(int m, int y) {
	if (m == 2) {
		return (is_leap(y) ? 29 : 28);
	}
	if (m == 7 || m == 8) {
		return 31;
	}
	if (m < 7) {
		return (m & 1 ? 31 : 30);
	}
	return (m & 1 ? 30 : 31);
}

inline int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int mn;
	cin >> mn;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		mn = lcm(mn, x);
	}
	cerr << "mn = " << mn << '\n';
	int y, m, d;
	char foo;
	cin >> y >> foo >> m >> foo >> d;
	d += mn;
	while (d > days(m, y)) {
		d -= days(m, y);
		m += 1;
		if (m > 12) {
			m -= 12;
			y += 1;
		}
	}
	cout << y << '/';
	cout << setfill('0') << setw(2) << m << '/';
	cout << setfill('0') << setw(2) << d << '\n';
	return 0;
} 