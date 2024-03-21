#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> pokedex;
    int answer = 0;
    int n = nums.size()/2;
    for(int i=0; i<nums.size(); i++){
        pokedex.insert(nums[i]);
    }
    if(pokedex.size() >= n) answer = n;
    else answer = pokedex.size();
    return answer;
}