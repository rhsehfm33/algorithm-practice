#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), mn(n, 2e9), mx(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn[i] = a[i];
        if (i) {
            mn[i] = min(mn[i], mn[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        mx[i] = a[i];
        if (i + 1 < n) {
            mx[i] = max(mx[i], mx[i + 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == mn[i] or a[i] == mx[i]) {
            cout << 1;
        } else {
            cout << 0;
        }
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