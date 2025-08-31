#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int R, C;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    fill(&dist1[0][0], &dist1[1001][1002], -1);
    fill(&dist2[0][0], &dist2[1001][1002], -1);
    //불이 몇 단위시간만에 전파되는지를 계산하기, BFS
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
        cin >> board[i];

    for (int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == 'F') {
                q.push({i, j});
                dist1[i][j] = 0;
            }
        }
    }

    //BFS 시작
    while (!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    //지훈의 BFS - dist가 불의 전파시간보다 작을경우 통과가능
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if(board[i][j] == 'J') {
                q.push({i, j});
                dist2[i][j] = 0;
                break;
            }
        }
        if(!q.empty()) break;
    }

    //BFS 시작
    while (!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << dist2[cur.first][cur.second] + 1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if(dist1[nx][ny] != -1 && dist2[cur.first][cur.second] + 1 >= dist1[nx][ny])
                continue;
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}