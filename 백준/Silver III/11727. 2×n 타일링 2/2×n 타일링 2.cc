#include <iostream>

using namespace std;

int main() {
	int pibo[1001] = { 0, };
	int n;

	pibo[0] = 1;
	pibo[1] = 3;

	cin >> n;

	for (int i = 2; i < n + 1; i++) {
		pibo[i] = (pibo[i - 1] + 2 * pibo[i - 2]) % 10007;
	}

	printf("%d\n", pibo[n - 1]);

	return 0;
}