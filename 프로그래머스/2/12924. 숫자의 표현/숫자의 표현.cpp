#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int start = 1, end = 1, sum = 0;
    while(start <= n) {
        while(sum < n && end <= n) {
            sum += end;
            end++;
        }
        if(sum == n) answer++;
        
        sum -= start;
        start++;
    } 
    return answer;
}