#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> dp(n + 1);
    dp[0] = 1;

    ll ans = 0;
    vector<ll> ndp(n + 1);
    for (ll i = n; i >= 1; --i) {
        fill(ndp.begin(), ndp.end(), 0);
        for (ll j = 0; j <= n - i; ++j) {
            ndp[j] = (ndp[j] + dp[j]) % m;
            ll avail = n - i + 1 - j;
            ll cal1 = (dp[j] * ((avail * i) % m)) % m;
            ndp[j + 1] = (ndp[j + 1] + cal1) % m;
        }
        swap(dp, ndp);
    }

    for (ll i = 0; i <= n; ++i) {
        ans = (ans + dp[i]) % m;
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