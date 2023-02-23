#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> dl;
	int n, m;
	int count = 0;
	string tmp;
	vector<string> dbj;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dl[tmp]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (dl.find(tmp) != dl.end()) {
			count++;
			dbj.push_back(tmp);
		}
	}

	sort(dbj.begin(), dbj.end());

	cout << count << '\n';
	for (int i = 0; i < count; i++) {
		cout << dbj[i] << '\n';
	}
}