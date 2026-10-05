#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct File {
    string original;
    string head;
    int number;
};

File to_file(string &s) {
    File new_file;
    int head = 0;
    while(s[head] < '0' || s[head] > '9') {
        head++;
    }
    int number = head;
    while(s[number] >= '0' && s[number] <= '9') {
        number++;
    }
    new_file.original = s;
    new_file.head = s.substr(0, head);
    transform(new_file.head.begin(), new_file.head.end(), new_file.head.begin(), ::tolower);
    new_file.number = stoi(s.substr(head, number));
    
    return new_file;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> v;
    for(auto& s : files) {
        v.push_back(to_file(s));
    }
    
    stable_sort(v.begin(), v.end(), [](const File& a, const File& b) {
        if(a.head != b.head)
            return a.head < b.head;
        return a.number < b.number;
    });
    
    for(auto& s : v) {
        answer.push_back(s.original);
    }
    return answer;
}