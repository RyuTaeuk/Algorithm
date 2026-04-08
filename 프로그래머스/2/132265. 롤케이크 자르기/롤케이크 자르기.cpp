#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int t_kinds[10001] = {0, };
    unordered_map<int, int> left;
    int right_size = 0;
    for(auto t: topping) {
        if(t_kinds[t] == 0)
            right_size++;
        t_kinds[t]++;
    }
    
    for(auto t: topping) {
        t_kinds[t]--;
        if(t_kinds[t] == 0)
            right_size--;
        
        left[t]++;
        if(left.size() == right_size)
            answer++;
    }
    
    return answer;
}