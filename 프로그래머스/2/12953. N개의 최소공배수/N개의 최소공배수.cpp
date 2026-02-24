#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getGCD(int a, int b) {
    int r;
    while(r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    
    for(int i=1; i<arr.size(); i++) {
        int gcd = getGCD(answer, arr[i]);
        answer = answer * arr[i] / gcd;
    }
    
    return answer;
}