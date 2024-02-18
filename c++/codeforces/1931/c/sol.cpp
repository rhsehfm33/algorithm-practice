#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int lc = 0, rc = 0;
    while (lc < n and a[lc] == a.front()) {
        ++lc;
    }
    while (n - 1 - rc >= 0 and a[n - 1 - rc] == a.back()) {
        ++rc;
    }

    if (a.front() == a.back()) {
        cout << max(0, n - lc - rc) << '\n';
    } else {
        cout << min(n - lc, n - rc) << '\n';
    }
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