#include <string>
#include <vector>

using namespace std;

bool visited[21] = {false, };

void dfs(vector<int>& numbers, int target, int& answer, int count = 0, int sum = 0){
    if(count == numbers.size() - 1) {
        if(sum + numbers[count] == target) answer++;
        if(sum - numbers[count] == target) answer++;
        return;
    }
    
    dfs(numbers, target, answer, count + 1, sum + numbers[count]);
    dfs(numbers, target, answer, count + 1, sum - numbers[count]);
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, answer);
    return answer;
}