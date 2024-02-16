#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, tmp, ans = 0;
	vector<int> p;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		p.push_back(tmp);
	}

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		ans += (n - i) * p[i];
	}

	cout << ans << '\n';

	return 0;
}