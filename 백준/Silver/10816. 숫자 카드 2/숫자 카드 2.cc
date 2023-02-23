#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map <int, int> cards;
	int n, m, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		cards[tmp]++;
	}

	scanf("%d", &m);
	int* r = new int[m];

	for (int i = 0; i < m; i++) {
		scanf("%d", &r[i]);
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", cards[r[i]]);
	}

	delete[] r;
	return 0;
}