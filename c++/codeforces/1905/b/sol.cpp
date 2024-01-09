#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> ind(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        ++ind[u];
        ++ind[v];
    }

    int lc = 0;
    for (int i = 1; i <= n; ++i) {
        lc += ind[i] == 1;
    }

    cout << lc / 2 + lc % 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}