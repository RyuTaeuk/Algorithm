#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    
    for(auto name : participant){
        if(m.find(name) == m.end()) m.insert(make_pair(name, 1));
        else m[name]++;
    }
    
    for(auto name : completion){
        m[name]--;
    }
    
    for(auto name : participant){
        if(m[name] > 0) {
            answer = name;
            break;
        }
    }
    return answer;
}