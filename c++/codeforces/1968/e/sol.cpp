#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    scanf("%d", &n);
    printf("1 1\n1 2\n");
    for (int i = 3; i <= n; ++i) {
        printf("%d %d\n", i, i);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}