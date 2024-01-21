#include <iostream>
#include <stack>

using namespace std;

int main() {
	char s[100001];
	stack<char> t;
	int i = 0;
	scanf("%[^\n]s", s);


	while (s[i] != NULL) {
		if (s[i] != ' ' && s[i] != '<' && s[i + 1] != NULL) {
			t.push(s[i]);
			i++;
			continue;
		}

		if (s[i + 1] == NULL) t.push(s[i]);
		while (!t.empty()) {
			cout << t.top();
			t.pop();
		}
		if (s[i] == ' ') cout << ' ';

		if (s[i] == '<') {
			while (s[i] != '>') {
				cout << s[i];
				i++;
			}
			cout << s[i];
		}

		i++;
	}

	return 0;
}