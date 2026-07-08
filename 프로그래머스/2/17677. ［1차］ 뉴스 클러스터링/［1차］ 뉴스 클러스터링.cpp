#include <string>
#include <set>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isAlphabet(char c) {
    return c >= 'a' && c <= 'z';
}

void countElement(string str, unordered_map<string, int> &m, set<string> &s) {
    for(int i=0; i<str.length()-1; i++) {
        if(!isAlphabet(str[i]) || !isAlphabet(str[i+1]))
            continue;
        
        string tmp = str.substr(i, 2);
        m[tmp]++;
        s.insert(tmp);
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), [](char c) {
        return tolower(c);
    });
    transform(str2.begin(), str2.end(), str2.begin(), [](char c) {
        return tolower(c);
    });
    unordered_map<string, int> m1, m2;
    set<string> s;
    countElement(str1, m1, s);
    countElement(str2, m2, s);
    int u_size = 0, i_size = 0;
    for(auto &x : s) {
        u_size += max(m1[x], m2[x]);
        i_size += min(m1[x], m2[x]);
    }
    if(u_size == 0) answer = 65536;
    else answer = (double)i_size / u_size * 65536;
    return answer;
}