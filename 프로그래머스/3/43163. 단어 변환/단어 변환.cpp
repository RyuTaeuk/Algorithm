#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chkString(string a, string b){
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) cnt++;
    }
    if (cnt == 1) return true;
    return false;
}

bool isExist(vector<string> words, string target){
    if(find(words.begin(), words.end(), target) != words.end()) return true;
    return false;
}

bool visited[51] = {false, };
int answer = 50;
void dfs(string cur, string target, vector<string> words, int cnt=0){
    if(answer <= cnt) return;
    if(cur == target) {
        answer = cnt;
        return;
    }
    for(int i = 0; i<words.size(); i++){
        if(chkString(cur, words[i]) && !visited[i])
            dfs(words[i], target, words, cnt + 1);
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    if(!isExist(words, target)) return 0;
    dfs(begin, target, words);
    return answer;
}