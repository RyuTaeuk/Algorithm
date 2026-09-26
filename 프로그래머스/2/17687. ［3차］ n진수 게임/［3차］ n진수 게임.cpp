#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 모든 숫자를 구한다?
// to string?
// p, 2p, 3p... 번째
string to_n_base(int n, int num) {
    string res = "";
    const string digits = "0123456789ABCDEF";
    if (num == 0) return "0";
    while(num > 0) {
        res += digits[num % n];
        num /= n;
    }
    reverse(res.begin(), res.end());
    return res;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "";
    int i = 0;
    while(str.size() < t*m) {
        str += to_n_base(n, i);
        i++;
    }
    
    for(int i=0; i<t; i++) {
        answer += str[m*i+p-1];
    }
    return answer;
}