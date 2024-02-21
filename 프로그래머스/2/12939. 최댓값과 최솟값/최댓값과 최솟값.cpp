#include <string>
#include <vector>
#include <climits>

using namespace std;

string solution(string s) {
    int x = 0;
    int max = INT_MIN, min = INT_MAX;
    int isMinus = 1;
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + (s[i] - '0');
        }
        else if (s[i] == '-') {
            isMinus = -1;
        }
        if (s[i] == ' ' || i == s.size() - 1) {
            x = isMinus * x;
            if (x < min) min = x;
            if (x > max) max = x;
            x = 0;
            isMinus = 1;
        }
    }
    answer = to_string(min) + ' ' + to_string(max);
    return answer;
}