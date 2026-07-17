#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<bool> b(n + 1);
    for (ll i = 0, bi; i < m; ++i) {
        cin >> bi;
        b[bi] = true;
    }
    ll mn1 = 0, mx1 = 0;
    for (ll i = 1, mn2 = 0, mx2 = 0; i <= n; ++i) {
        mn2 = mn1 + a[i];
        mx2 = mx1 + a[i];
        if (b[i]) {
            mn2 = min(mn2, -(mx1 + a[i]));
            mx2 = max(mx2, -(mn1 + a[i]));
        }
        mn1 = mn2;
        mx1 = mx2;
    }
    cout << mx1 << '\n';
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