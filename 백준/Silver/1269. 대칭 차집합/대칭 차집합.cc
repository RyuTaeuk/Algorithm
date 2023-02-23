#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<int, int> a;
	int n, m;
	int count = 0;
	int tmp;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[tmp]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (a.find(tmp) != a.end()) {
			n--;
		}
		else {
			n++;
		}
	}
	cout << n << '\n';

	return 0;
}