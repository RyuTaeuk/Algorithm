#include <string>
#include <vector>

using namespace std;

// 2x2를 인식시키기 < 그냥 복사본 하나만들어서 [i][i+1] [i+1][i] [i+1][i+1] 보면서 마킹 ㄱㄱ
// 중력적용
// 언제까지? pop할게 없을때까지
void drop(vector<string> &board) {
    for(int i=0; i<board[0].size(); i++) { //행 진행
        int write = board.size() - 1;
        for(int read = board.size() - 1; read >= 0; read--) { //열 역순
            if(board[read][i] != '-') {
                board[write][i] = board[read][i];
                write--;
            }
        }
        
        for(; write >= 0; write--) {
            board[write][i] = '-';
        }
    }
}

int pop(vector<string> &board) {
    int count = 0;
    vector<vector<bool>> marker(board.size(), vector<bool>(board[0].size(), false));
    
    for(int i=0; i<board.size()-1; i++) {
        for(int j=0; j<board[i].size()-1; j++) {
            if(board[i][j] != '-'
              && board[i][j] == board[i][j+1]
              && board[i][j] == board[i+1][j]
              && board[i][j] == board[i+1][j+1]) {
                marker[i][j] = true;
                marker[i][j+1] = true;
                marker[i+1][j] = true;
                marker[i+1][j+1] = true;
            }
        }
    }
    
    for(int i=0; i<marker.size(); i++) {
        for(int j=0; j<marker[i].size(); j++) {
            if(marker[i][j]) {
                board[i][j] = '-';
                count++;
            }
        }
    }
    drop(board);
    return count;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true) {
        int count = pop(board);
        if(count == 0) {
            break;
        }
        
        answer += count;
    }
    return answer;
}