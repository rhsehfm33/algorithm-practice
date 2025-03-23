#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    if (k == 1) {
        ll ans = a.front() + a.back();
        ll mx = max(a.front(), a.back());
        for (ll i = 1; i < n - 1; ++i) {
            ans = max(ans, mx + a[i]);
        }
        cout << ans << '\n';
        return;
    }

    ++k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= k; ++j) {
            if (j + 1 <= k) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[n][k] << '\n';
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