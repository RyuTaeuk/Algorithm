#include <string>
#include <vector>
#include <bitset>

using namespace std;

// XOR 후 카운트했을때 2 이하
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto& n : numbers) {
        if(n % 2 == 0) {
            answer.push_back(n+1);
        }
        else {
            bitset<64> b(n);
            for(int i=0; i<64; i++) {
                if(b[i] == 1 && b[i+1] == 0) {
                    b[i+1] = 1;
                    b[i] = 0;
                    break;
                }
            }
            answer.push_back(b.to_ullong());
        }
    }
    
    return answer;
}