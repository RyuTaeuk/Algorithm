#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int getTime(string t1, string t2) { // t2 > t1
    stringstream ss1(t1);
    stringstream ss2(t2);
    int h1, h2, m1, m2;
    string h1_str, h2_str, m1_str, m2_str;
    getline(ss1, h1_str, ':');
    getline(ss2, h2_str, ':');
    getline(ss1, m1_str, ':');
    getline(ss2, m2_str, ':');
    
    h1 = stoi(h1_str);
    h2 = stoi(h2_str);
    m1 = stoi(m1_str);
    m2 = stoi(m2_str);
    cout << h2 << '\n';
    
    return (h2 - h1) * 60 + m2 - m1;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<vector<string>> v(records.size(), vector<string>(3));
    for(int i=0; i<records.size(); i++) {
        string buffer;
        stringstream ss(records[i]);
        for(int j=0; j<3; j++) {
            getline(ss, buffer, ' ');
            v[i][j] = buffer;
        }
    }
    if(records.size() > 1)
        cout << getTime(v[0][0], v[1][0]) << '\n';
    return answer;
}