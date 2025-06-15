#include <cstring>
#include <sstream>
#include <cstdio>

using namespace std;

class mySet{
    private:
    bool S[20];

    public:
    mySet() {
        for(int i = 0; i < 20; i++) {
            S[i] = false;
        }
    };
    void add(int x) {
        S[x-1] = true;
    };
    void remove(int x) {
        S[x-1] = false;
    };
    bool check(int x) {
        return S[x-1];
    };
    void toggle(int x) {
        S[x-1] = !S[x-1];
    };
    void all() {
        for(int i = 0; i < 20; i++) {
            S[i] = true;
        }
    };
    void empty() {
        for(int i = 0; i < 20; i++) {
            S[i] = false;
        }
    };
};

int main() {
    int n;
    char str[100];
    mySet s;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%s", str);
        if (strcmp(str, "add") == 0) {
            int x;
            scanf("%d", &x);
            s.add(x);
        } else if (strcmp(str, "remove") == 0) {
            int x;
            scanf("%d", &x);
            s.remove(x);
        } else if (strcmp(str, "check") == 0) {
            int x;
            scanf("%d", &x);
            printf("%d\n", s.check(x));
        } else if (strcmp(str, "toggle") == 0) {
            int x;
            scanf("%d", &x);
            s.toggle(x);
        } else if (strcmp(str, "all") == 0) {
            s.all();
        } else if (strcmp(str, "empty") == 0) {
            s.empty();
        }
    }
    return 0;
}