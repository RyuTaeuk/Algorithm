#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool allDiscounted(vector<string>& want, vector<int>& number, unordered_map<string, int>& m) {
    for(int i=0; i<want.size(); i++) {
        if(m[want[i]] < number[i])
            return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // 처음 10일치를 unordered_map에 저장
    unordered_map<string, int> m;
    for(int i=0; i<10; i++)
        m[discount[i]]++;
    // 첫날에 가입가능한가?
    if(allDiscounted(want, number, m))
        answer++;
    
    for(int i=10; i<discount.size(); i++) {
        m[discount[i-10]]--;
        m[discount[i]]++;
        if(allDiscounted(want, number, m))
            answer++;
    }
    
    return answer;
}