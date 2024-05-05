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

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1e18));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= k; ++j) {
            for (ll nj = 0, mn = a[i]; nj <= k - j and i + nj < n; ++nj) {
                mn = min(mn, a[i + nj]);
                dp[i + nj + 1][j + nj] = min(dp[i + nj + 1][j + nj], dp[i][j] + mn * (nj + 1));
            }
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
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