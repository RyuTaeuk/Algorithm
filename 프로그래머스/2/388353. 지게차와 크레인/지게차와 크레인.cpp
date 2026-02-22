#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 50
#define MAX_M 50

using namespace std;

// 지게차: BFS
// 크레인: 완탐
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[MAX_N][MAX_M];
int n, m;
bool inRange(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

void lift(char target, vector<string>& storage) {
    vector<pair<int, int>> del;
    fill(visited[0], visited[MAX_N], false);
    // 가장자리를 돌면서
    // 1. 타겟을 보면 삭제
    // 2. 공백을 보면 큐에 넣어 BFS 시작
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i != 0 && i != n-1 && j != 0 && j != m-1)
                continue;
            
            if(storage[i][j] == target)
                del.push_back({i, j});
            else if(storage[i][j] == ' ') {
                // BFS 시작
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        
                        if(!inRange(nx, ny) || visited[nx][ny])
                            continue;
                        // 여기서도 1. 타겟이면 삭제 (visited 업데이트 조심)
                        if(storage[nx][ny] == target) {
                            del.push_back({nx, ny});
                            visited[nx][ny] = true;
                        }
                        // 2. 공백이면 더 안으로 탐색하기
                        else if(storage[nx][ny] == ' ') {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    // 삭제 처리
    for(auto i : del)
        storage[i.first][i.second] = ' ';
}

void crain(char target, vector<string>& storage) {
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            if(storage[i][j] == target)
                storage[i][j] = ' ';
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size();
    m = storage[0].size();
    
    for(auto request : requests) {
        if(request.size() == 1)
            lift(request[0], storage);
        else
            crain(request[0], storage);
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(storage[i][j] != ' ')
                answer++;
    
    return answer;
}