#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int isX = 0, isNotX = 0;
    char x = s[0];
    for (int i=0; i<s.size(); i++){
        if(s[i] == x){
            isX++;
        }
        else isNotX++;
        
        if (i == s.size()-1) answer++;
        else if(isX == isNotX){
            x = s[i+1];
            answer++;
            isX = 0;
            isNotX = 0;
        }
    }
    return answer;
}