#include <string>
#include <vector>

using namespace std;

vector<string> optimal;
bool used[10001] = {false, };
void dfs(vector<vector<string>> tickets, vector<string> cur, string departure){
    if(cur.size() == tickets.size() + 1) { // 리턴 조건 : 항공권을 모두 사용했을 때
        if(optimal.empty()) optimal = cur;
        else {
            for(int i = 0; i < cur.size(); i++){
                if (cur[i] > optimal[i]) break; //사전순 판별
                else if(cur[i] < optimal[i]) {
                    optimal = cur;
                    break;
                }
            }
        }
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++){
        if(used[i] == false && tickets[i][0] == departure) {
            departure = tickets[i][1];
            cur.push_back(departure);
            used[i] = true;
            dfs(tickets, cur, departure);
            used[i] = false;
            cur.pop_back();
            departure = tickets[i][0];
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> cur;
    cur.push_back("ICN");
    dfs(tickets, cur, "ICN");
    answer = optimal;
    
    return answer;
}