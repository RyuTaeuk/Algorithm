#include <iostream>
#include <stack>

using namespace std;

int main() {
	int s[1000001];
	int ans[1000001] = { 0, };
	stack<int> t;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!t.empty() && t.top() <= s[i])
			t.pop();

		if (t.empty()) ans[i] = -1;
		else ans[i] = t.top();

		t.push(s[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}