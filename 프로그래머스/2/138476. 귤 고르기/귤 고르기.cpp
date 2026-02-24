#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;
    for(int i=0; i<tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    
    vector<pair<int, int>> sizes(m.begin(), m.end());
    sort(sizes.begin(), sizes.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    
    int sum = 0;
    for(const auto& it: sizes) {
        if(sum >= k)
            break;
        sum += it.second;
        answer++;
    }
    
    return answer;
}