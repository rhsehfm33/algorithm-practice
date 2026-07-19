#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (int i = 0, b = 0, c1 = 0, mn = 1e6; i < n; ++i) {
        b += (a[i] <= 2 ? 1 : -1);
        if (b - mn >= 0 and i + 1 < n) {
            cout << "YES\n";
            return;
        }
        c1 += (a[i] == 1);
        if (c1 >= (i + 2) / 2) {
            mn = min(mn, b);
        }
    }
    cout << "NO\n";
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