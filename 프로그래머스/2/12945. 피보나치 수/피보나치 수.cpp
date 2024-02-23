#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer;
    vector<int> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < n + 1; i++){
        fib[i] = (fib[i-1]+fib[i-2]) % 1234567;
    }
    answer = fib[n];
    return answer;
}