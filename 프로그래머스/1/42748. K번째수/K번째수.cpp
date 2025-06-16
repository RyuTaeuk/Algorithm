#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    int i, j, k;
    for(int index=0; index<commands.size(); index++){
        i = commands[index][0] - 1;
        j = commands[index][1];
        k = commands[index][2] - 1;
        for(i; i<j; i++){
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k]);
        tmp.clear();
    }
    return answer;
}