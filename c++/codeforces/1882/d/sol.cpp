#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void go(vector<vector<ll>>& u2v, vector<ll>& a, vector<ll>& dp, vector<ll>& sums, ll ci, ll pi) {
    sums[ci] = 1;
    for (ll ni : u2v[ci]) {
        if (ni != pi) {
            go(u2v, a, dp, sums, ni, ci);
            sums[ci] += sums[ni];
            dp[ci] += dp[ni];
        }
    }
    dp[ci] += pi != -1 ? (a[ci] ^ a[pi]) * sums[ci] : 0;
}

void go2(vector<vector<ll>>& u2v, vector<ll>& a, vector<ll>& dp, vector<ll>& sums, vector<ll>& ans, ll ci, ll pi) {
    ans[ci] = dp[ci];
    if (pi != -1) {
        ans[ci] -= (a[ci] ^ a[pi]) * sums[ci];
        ans[ci] += ans[pi] - dp[ci] + (a.size() - 1 - sums[ci]) * (a[ci] ^ a[pi]);
    }
    for (ll ni : u2v[ci]) {
        if (ni != pi) {
            go2(u2v, a, dp, sums, ans, ni, ci);
        }
    }
}

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    vector<ll> dp(n + 1), sums(n + 1), ans(n + 1);
    go(u2v, a, dp, sums, 1, -1);
    go2(u2v, a, dp, sums, ans, 1, -1);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}