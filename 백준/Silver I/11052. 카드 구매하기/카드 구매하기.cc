#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int dp[1001] = { 0, };
	int p[10001] = { 0, };
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}