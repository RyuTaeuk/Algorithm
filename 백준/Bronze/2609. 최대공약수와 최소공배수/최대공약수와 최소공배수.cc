#include <iostream>

using namespace std;

int main() {
	int a, b, r = 1, gcd, lcd;
	cin >> a >> b;
	lcd = a * b;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	gcd = a;
	lcd /= gcd;
	cout << gcd << ' ' << lcd << '\n';
	return 0;
}