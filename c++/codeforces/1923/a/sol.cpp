#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int l = 100, r = -1, n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) {
            l = min(l, i);
            r = max(r, i);
        }
    }

    int ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += (a[i] == 0);
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