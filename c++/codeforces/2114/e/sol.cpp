#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void go(vector<ll>& a, vector<vector<ll>>& u2v, vector<array<ll, 2>>& dp, ll u, ll p) {
    dp[u][0] = a[u] - min(0ll, dp[p][1]);
    dp[u][1] = a[u] - max(0ll, dp[p][0]);
    for (ll v : u2v[u]) {
        if (v != p) {
            go(a, u2v, dp, v, u);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> u2v(n + 1);
    for (ll i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }
    vector<array<ll, 2>> dp(n + 1);
    go(a, u2v, dp, 1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << dp[i][0] << ' ';
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