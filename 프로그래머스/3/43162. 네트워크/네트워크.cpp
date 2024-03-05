#include <string>
#include <vector>

using namespace std;

bool visited[201] = {false, };

void dfs(int x, vector<vector<int>> com){
    for(int i=0; i<com.size(); i++){
        if(visited[i] == false && com[x][i] == 1){
            visited[i] = true;
            dfs(i, com);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}