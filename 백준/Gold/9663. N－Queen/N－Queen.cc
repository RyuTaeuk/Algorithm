#include <iostream>
using namespace std;

int n, result = 0;
int matrix[16];


int checking(int idx) {
    for (int j = 0; j < idx; j++) {
        if (matrix[idx] == matrix[j] || idx - j == abs(matrix[idx] - matrix[j])) return 0;
    }
    return 1;
}

void searching(int idx) {
    if (idx == n) {
        result++;
        return;
    }


    for (int i = 0; i < n; i++) {
            matrix[idx] = i;
            //같은 행/대각선에 퀸이 존재하는지

            if(checking(idx)) searching(idx + 1);
    }


    return;
}

int main() {

    cin >> n;
    searching(0);
    cout << result << '\n';

    return 0;
}