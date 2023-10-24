#include <string>
#include <vector>

using namespace std;

vector<int> op(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] >= 50 && arr[i] % 2 == 0) 
            arr[i] /= 2;
        else if(arr[i] < 50 && arr[i] % 2 == 1)
            arr[i] = arr[i] * 2 + 1;
    }
    return arr;
}

int solution(vector<int> arr) {
    vector<int> prevarr = arr;
    int answer = 0;
    while(true){
        arr = op(arr);
        if(arr == prevarr)
            break;
        else {
            answer++;
            prevarr = arr;
        }
    }

    return answer;
}