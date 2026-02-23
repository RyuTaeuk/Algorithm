#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_N 50000

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int s = 0;
    for(int e = people.size()-1; e >= s; e--) {
        if(people[e] + people[s] <= limit)
            s++;
        
        answer++;
    }
    return answer;
}