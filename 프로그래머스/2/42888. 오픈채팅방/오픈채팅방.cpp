#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickname;
    for(auto& s : record) {
        stringstream ss(s);
        string cmd, uid;
        ss >> cmd >> uid;
        if(cmd == "Enter" || cmd == "Change") {
            string nick;
            ss >> nick;
            nickname[uid] = nick;
        }
    }
    
    for(auto& s : record) {
        stringstream ss(s);
        string cmd, uid;
        ss >> cmd >> uid;
        if(cmd == "Enter") {
            answer.push_back(nickname[uid] + "님이 들어왔습니다.");
        }
        else if(cmd == "Leave") {
            answer.push_back(nickname[uid] + "님이 나갔습니다.");
        }
    }
    return answer;
}