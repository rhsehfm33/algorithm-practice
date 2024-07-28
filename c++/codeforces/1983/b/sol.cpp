#include <bits/stdc++.h>

using namespace std;

int _ti;

int add(int n1, int n2) {
    return (n1 + n2 + 3) % 3;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (auto& ai : a) {
        for (auto & aij : ai) {
            scanf("%1d", &aij);
        }
    }
    for (auto& bi : b) {
        for (auto & bij : bi) {
            scanf("%1d", &bij);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int d = add(b[i][j], -a[i][j]);
            a[i][j] = add(a[i][j], d);
            a[n - 1][m - 1] = add(a[n - 1][m - 1], d);
            a[i][m - 1] = add(a[i][m - 1], 2 * d);
            a[n - 1][j] = add(a[n - 1][j], 2 * d);
        }
    }

    if (a == b) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}