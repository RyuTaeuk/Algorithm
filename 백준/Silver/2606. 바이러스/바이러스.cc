#include <iostream>
#include <utility>
#include <vector>
using namespace std;


vector<int> v[101];
vector<int> visited(101);
int com, node, cnt=0;
void dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (visited[v[x][i]] == 0) { 
            visited[v[x][i]] = 1;
            cnt++;
            dfs(v[x][i]);
        }
    }
    return;
}

int main(void) {
    int x, y;
    scanf("%d", &com);
    scanf("%d", &node);

    for (int i = 0; i < node; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    visited[1] = 1;
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}