#include <iostream>

using namespace std;

int insertion_sort() {
    // TODO: Sort Implementation
    int cnt = 0, i, j, key;
    int arr[20] = {0, };
    for (int i = 0; i < 20; i++){
        cin >> arr[i];
    }

    for (i = 1; i < 20; i++){
        key = arr[i];
        for (j = i - 1; j >= 0; j--){
            if(arr[j] > key) {
                arr[j + 1] = arr[j];
                cnt++;
            }
            else break;
        }
        arr[j + 1] = key;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p, n;
    int arr[20] = {0, };
    cin >> p;
    while (p--){
        cin >> n;
        cout << n << " " << insertion_sort() << '\n';
    }

    return 0;
}