#include <iostream>

using namespace std;

int main() {
	int dp[1001] = { 0, };
	int t;
	int n;

	cin >> t;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	for (int i = 3; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	

	for (int i = 0; i < t; i++) {
		cin >> n;
		printf("%d\n", dp[n - 1]);
	}

	return 0;
}