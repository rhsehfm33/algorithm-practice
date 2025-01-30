#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    int d1 = 2e9, d2 = 2e9;
    for (int i = 0; i < n; ++i) {
        int d = a[i] - b[i];
        if (d < d1) {
            d2 = d1;
            d1 = d;
        } else if (d < d2) {
            d2 = d;
        }
    }

    cout << (d1 + d2 >= 0 ? "YES\n" : "NO\n");
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