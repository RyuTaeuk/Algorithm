#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int count1 = 0;

int fibonacci1(int n) {
	if (n == 1 || n == 2) return 1;
	else {
		count1++;
		return (fibonacci1(n - 1) + fibonacci1(n - 2));
	}
}

int fibonacci2(int n) {
	int f[40];
	int count2 = 0;
	f[0] = 1, f[1] = 1;
	for (int i = 2; i < n; i++) {
		count2++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return count2;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d %d\n", fibonacci1(n), fibonacci2(n));

	return 0;
}