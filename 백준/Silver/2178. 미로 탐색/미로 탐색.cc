#include <iostream>
#include <deque>
using namespace std;

bool visited[101][101] = { false, };
int maze[101][101] = { 0, };
int dist[101][101] = { 0, };
void bfs(int n, int m) {
	deque<pair<int, int>> d;
	dist[0][0] = 1;
	int x, y;
	visited[0][0] = true;
	d.push_back(make_pair(0, 0));
	while (!d.empty()) {
		x = d.front().first;
		y = d.front().second;
		d.pop_front();
		if (maze[y][x + 1] == 1 && x < m && !visited[y][x + 1]) { // 상하좌우탐색(우)
			d.push_back(make_pair(x + 1, y));
			visited[y][x + 1] = true;
			dist[y][x + 1] = dist[y][x] + 1;
		}
		if (maze[y][x - 1] == 1 && x >= 0 && !visited[y][x - 1]) { // 상하좌우탐색(좌)
			d.push_back(make_pair(x - 1, y));
			visited[y][x - 1] = true;
			dist[y][x - 1] = dist[y][x] + 1;
		}
		if (maze[y + 1][x] == 1 && y < n && !visited[y + 1][x]) { // 상하좌우탐색(상)
			d.push_back(make_pair(x, y + 1));
			visited[y + 1][x] = true;
			dist[y + 1][x] = dist[y][x] + 1;
		}
		if (maze[y - 1][x] == 1 && y >= 0 && !visited[y - 1][x]) { // 상하좌우탐색(하)
			d.push_back(make_pair(x, y - 1));
			visited[y - 1][x] = true;
			dist[y - 1][x] = dist[y][x] + 1;
		}
	}
	cout << dist[n - 1][m - 1] << '\n';
	return;
}

int main() {
	int n, m;
	
	string str;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			maze[i][j] = str[j]-'0';
		}
	}

	bfs(n, m);
}