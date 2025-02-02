#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, m, x;
    cin >> n >> m >> x;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto& ai : a) {
        for (auto& aij : ai) {
            cin >> aij;
        }
    }

    vector<vector<ll>> dp(m + 1, vector<ll>(m, 1e18));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        vector<vector<ll>> ndp(m + 1, vector<ll>(m, 1e18));
        for (ll j = 0; j < m; ++j) {
            for (ll k = 0; k < m; ++k) {
                dp[j][k] = min(dp[j][k], dp[j][0] + x * k);
            }
        }
        for (ll j = 0; j < m; ++j) {
            for (ll k = 0; k < m; ++k) {
                ndp[j][0] = min(ndp[j][0], dp[j][k] + a[i][(j + k) % m]);
                dp[j + 1][k] = min(dp[j + 1][k], dp[j][k] + a[i][(j + k) % m]);
            }
        }
        swap(dp, ndp);
    }

    cout << dp[m - 1][0] << '\n';
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