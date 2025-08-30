#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int board[501][501] = {0, };
    bool vis[501][501] = {false, };
    int count = 0, mx = 0;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    //BFS 시작
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(!board[i][j] || vis[i][j]) continue;
            vis[i][j] = true;
            int area = 0;
            count++;
            q.push({i, j});
            while (!q.empty()){
                area++;
                pair<int, int> cur = q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << count << '\n' << mx << '\n';
    return 0;
}