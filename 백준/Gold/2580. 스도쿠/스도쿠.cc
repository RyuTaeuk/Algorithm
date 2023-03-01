#include <iostream>
#include <vector>
using namespace std;

int n = 0, result = 0, solve = 0;
int matrix[10][10];
vector<pair <int, int>> problems;

int check(int x, int y) {
    int area_x = x / 3;
    int area_y = y / 3;
    for (int i = 0; i < 9; i++) {
        if (matrix[x][i] == matrix[x][y] && i != y)
            return 0;
        if (matrix[i][y] == matrix[x][y] && i != x)
            return 0;
    }
    for (int i = 3 * area_x; i < 3 * area_x + 3; i++) {
        for (int j = 3 * area_y; j < 3 * area_y + 3; j++) {
            if (matrix[i][j] == matrix[x][y] &&
                (i != x && j != y)) {
                return 0;
            }
        }
    }
    return 1;
}

void searching(int cnt) {
    if (cnt == n) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
        solve = 1;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        matrix[problems[cnt].first][problems[cnt].second] = i;
        if (check(problems[cnt].first, problems[cnt].second))
            searching(cnt + 1);
        if (solve) return;
    }
    matrix[problems[cnt].first][problems[cnt].second] = 0;
    return;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0) {
                problems.push_back(make_pair(i, j));
                n++;
            }
        }
    }
    searching(0);

    return 0;
}