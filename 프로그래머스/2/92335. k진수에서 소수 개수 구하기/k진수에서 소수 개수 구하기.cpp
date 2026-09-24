#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string to_k_base(int n, int k) {
    string res = "";
    while(n > 0) {
        res += to_string(n % k);
        n /= k;
    }
    
    reverse(res.begin(), res.end());
    return res;
}

bool isPrime(long long num) {
    if(num < 2) return false;
    for(long long i = 3; i*i <= num; i+=2) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str = to_k_base(n, k);
    stringstream ss(str);
    string token;
    while(getline(ss, token, '0')) {
        if(token.empty()) continue;
        
        long long num = stoll(token);
        if(isPrime(num)) {
            answer++;
        }
    }
    
    return answer;
}