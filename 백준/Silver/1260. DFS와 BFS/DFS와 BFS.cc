#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool g[1001][1001] = { false, };
bool visited1[1001] = { false, }; //dfs의 방문기록
bool visited2[1001] = { false, }; //bfs의 방문기록
deque<int> q;

void dfs(int v, int n) {
	visited1[v] = true;
	printf("%d ", v);
	for (int i = 1; i <= n; i++) {
		if (g[v][i] == true && visited1[i] == false) {
			dfs(i, n);
		}
	}
	return;
}

void bfs(int v, int n) {
	int x;
	visited2[v] = true;
	q.push_back(v);
	while (!q.empty()) {
		x = q.front();
		q.pop_front();
		printf("%d ", x);
		for (int i = 1; i <= n; i++) {
			if (g[x][i] == true && visited2[i] == false) {
				q.push_back(i);
				visited2[i] = true;
			}
		}
	}
	return;
}

int main() {
	int n, m, v, x, y;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		g[x][y] = true;
		g[y][x] = true;
	}
	dfs(v, n);
	printf("\n");
	bfs(v, n);

	return 0;
}