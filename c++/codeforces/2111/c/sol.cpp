#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, ans = 1e18;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0, pi = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != a[pi]) {
            pi = i;
        }
        ans = min(ans, pi * a[i] + (n - i - 1) * a[i]);
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