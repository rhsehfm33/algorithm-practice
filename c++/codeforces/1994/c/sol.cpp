#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<ll> dp(n, 1);
    ll ans = (1 + n) * n / 2;
    for (ll l = 0, r = 0, g = 0; r < n; ++r) {
        g += a[r];
        while (l <= r and g > x) {
            if (r + 1 < n) {
                dp[r + 1] += dp[l];
            }
            g -= a[l];
            ans -= dp[l];
            ++l;
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