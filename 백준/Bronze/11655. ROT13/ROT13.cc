#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;

	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			s[i] = ((s[i] - 'A' + 13) % 26) + 'A';
		}
		else if ('a' <= s[i] && s[i] <= 'z') {
			s[i] = ((s[i] - 'a' + 13) % 26) + 'a';
		}
	}

	cout << s << '\n';
	return 0;
}