#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, b = 0, ans = 1;
    cin >> n;
    vector<int> a(n), d(20, -1);
    for (auto& ai : a) {
        cin >> ai;
        b |= ai;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (a[i] & (1 << j)) {
                d[j] = i;
            }
            if (b & (1 << j)) {
                ans = max(ans, i - d[j] + 1);
            }
        }
    }
    cout << ans << '\n';
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