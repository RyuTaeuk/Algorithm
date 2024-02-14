#include <iostream>

using namespace std;

int main() {
	int pibo[1001] = { 0, };
	int n;

	pibo[0] = 1;
	pibo[1] = 1;

	cin >> n;

	for (int i = 2; i < n + 1; i++) {
		pibo[i] = (pibo[i - 1] + pibo[i - 2]) % 10007;
	}

	printf("%d\n", pibo[n]);

	return 0;
}