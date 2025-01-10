#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), c(n + 1);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (int i = 0, qi; i < k; ++i) {
        cin >> qi;
        ++c[qi];
    }

    for (auto ai : a) {
        cout << (k - c[ai] == n - 1 ? '1' : '0');
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}