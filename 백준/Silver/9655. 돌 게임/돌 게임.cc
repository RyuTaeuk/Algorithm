#include <string>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << "CY\n";
    } else {
        cout << "SK\n";
    }
    return 0;
}