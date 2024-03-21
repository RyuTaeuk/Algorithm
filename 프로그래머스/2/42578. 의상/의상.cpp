#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    
    for(int i=0; i<clothes.size(); i++){
        if(map.find(clothes[i][1]) == map.end()) {
            map.insert(make_pair(clothes[i][1], 1));
        }
        else map[clothes[i][1]]++;
    }
    
    for(auto i=map.begin(); i!=map.end(); i++){
        answer *= (i->second+1);
    }
    answer--;
    return answer;
}