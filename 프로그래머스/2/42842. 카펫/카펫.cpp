#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int height, width;

    for (int i = 1; i <= sqrt(yellow); i++) {
        if (yellow % i != 0) continue;

        height = i;
        width = yellow / i;
        if (2 * (height + 1) + 2 * (width + 1) == brown) {
            answer.push_back(width + 2);
            answer.push_back(height + 2);
            break;
        }
    }
    return answer;
}