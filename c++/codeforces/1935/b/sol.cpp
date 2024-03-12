#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    scanf("%d", &n);
    vector<queue<int>> n2i(n + 1);
    for (int i = 1, ai; i <= n; ++i) {
        scanf("%d", &ai);
        n2i[ai].push(i);
    }

    int i1 = 1, n1 = 0, n2 = 0;
    while (n1 <= n and n2i[n1].size()) {
        i1 = max(i1, n2i[n1].front());
        ++n1;
    }
    while (n2 <= n) {
        while (n2i[n2].size() and n2i[n2].front() <= i1) {
            n2i[n2].pop();
        }
        if (n2i[n2].size()) {
            ++n2;
        } else {
            break;
        }
    }

    if (n1 == n2) {
        printf("2\n1 %d\n%d %d\n", i1, i1 + 1, n);
    } else {
        printf("-1\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}