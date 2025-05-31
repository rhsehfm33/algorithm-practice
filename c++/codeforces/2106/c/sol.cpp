#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    int mn = 2e9, mx = -1, s = -1;
    for (int i = 0; i < n; ++i) {
        if (b[i] != -1) {
            if (s == -1) {
                s = a[i] + b[i];
            }
            if (s != a[i] + b[i]) {
                cout << "0\n";
                return;
            }
        } else {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }

    if (s != -1) {
        cout << (mn + k >= s and mx <= s ? 1 : 0) << '\n';
    } else {
        cout << max(0, mn + k - mx + 1) << '\n';
    }
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