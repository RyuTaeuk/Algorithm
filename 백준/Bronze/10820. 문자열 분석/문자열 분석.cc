#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	int a[4] = { 0, };

	while (true) {
		getline(cin, s);
		if (cin.eof()) break;
		for (int j = 0; j < s.size(); j++) {
			if ('a' <= s[j] && s[j] <= 'z') {
				a[0]++;
			}
			if ('A' <= s[j] && s[j] <= 'Z') {
				a[1]++;
			}
			if ('0' <= s[j] && s[j] <= '9') {
				a[2]++;
			}
			if (s[j] == ' ') {
				a[3]++;
			}
		}
		
		for (int j = 0; j < 4; j++) {
			cout << a[j] << ' ';
			a[j] = 0;
		}
		cout << '\n';
	}

	return 0;
}