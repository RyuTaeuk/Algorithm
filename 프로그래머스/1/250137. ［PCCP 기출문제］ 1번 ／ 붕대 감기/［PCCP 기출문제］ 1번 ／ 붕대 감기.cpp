#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
	int c = 0;
	int answer = health;
	int t = bandage[0];
	int x = bandage[1];
	int y = bandage[2];

	for (int i = 0; i < attacks.size(); i++) {
		answer -= attacks[i][1];
		if (answer <= 0) {
			answer = -1;
			break;
		}
		if (i < attacks.size() - 1) {
			int diff = attacks[i + 1][0] - attacks[i][0] - 1;
			answer += diff / t * y + diff * x;
		}
		if (answer > health) answer = health;
	}

	return answer;
}