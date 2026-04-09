#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> freq;
    // 빈도 순 정렬;; 천잰가? 난 이런거 생각못함
    string tmp = "";
    for(char c : s) {
        if(c >= '0' && c <= '9') {
            tmp += c;
        }
        else if(!tmp.empty()) {
            freq[stoi(tmp)]++;
            tmp = "";
        }
    }
    
    vector<pair<int, int>> v(freq.begin(), freq.end());
    
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    
    for(auto p : v) {
        answer.push_back(p.first);
    }
    
    return answer;
}