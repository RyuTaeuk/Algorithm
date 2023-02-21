#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int bs(int len, string target, string* s) {
	int left = 0;
	int mid;
	int right = len - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (s[mid] == target) {
			return 1;
		}
		else if (s[mid] > target) {
			right = mid - 1;
		}
		else if (s[mid] < target) {
			left = mid + 1;
		}
	}
	return 0;
}

int main() {
	int n, m, count = 0;
	scanf("%d %d", &n, &m);
	string* s = new string[n];
	string u;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n);

	for (int i = 0; i < m; i++) {
		cin >> u;
		if(bs(n, u, s)) count++;
	}

	printf("%d\n", count);

	delete[] s;
	return 0;
}