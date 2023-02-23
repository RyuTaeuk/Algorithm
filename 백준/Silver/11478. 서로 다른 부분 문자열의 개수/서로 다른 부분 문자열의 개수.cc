#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> a;
	string s, tmp;
	int count = 0;
	cin >> s;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j <= s.length() - i; j++) {
			tmp = s.substr(j, i);
			a[tmp]++;
		}
	}

	cout << a.size() << '\n';

	return 0;
}