#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	map <string, int> pindex;
	map <int, string> name;
	vector<string> prob;
	int n, m;
	string tmp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		pindex.insert(pair<string, int>(tmp, i + 1));
		name.insert(pair<int, string>(i + 1, tmp));
	}

	for (int i = 0; i < m; i++) {
		cin >> tmp;
		prob.push_back(tmp);
 	}
	for (int i = 0; i < m; i++) {
		if ((prob[i].front() >= 'A' && prob[i].front() <= 'Z')
			|| (prob[i].front() >= 'a' && prob[i].front() <= 'z')) cout << pindex[prob[i]] << '\n';
		else cout << name[stoi(prob[i])] << '\n';
	}

	return 0;
}