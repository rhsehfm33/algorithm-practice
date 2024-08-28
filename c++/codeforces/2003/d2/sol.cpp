#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

int _ti;

ll dfs(vvll& dp, vvll& u2v, ll i, ll j) {
    if (i >= dp.size() or u2v.size() == 0) {
        return i;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    dp[i][j] = i;
    for (ll v : u2v[i]) {
        if (j == 1 or u2v[i].size() > 1) {
            dp[i][j] = max(dp[i][j], dfs(dp, u2v, v, 1));
        }
    }
    return dp[i][j];
}

void solve() {
    ll n, m, sum = 0, mx = 0, ans = 0; cin >> n >> m;
    vvll a(n);
    for (ll i = 0; i < n; ++i) {
        ll li; cin >> li;
        a[i].resize(li);
        for (ll j = 0; j < li; ++j) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
        sum += li;
    }

    vvll dp(sum + 1, vll(2, -1)), u2v(sum + 1);
    for (auto& ai : a) {
        vector<ll> uv;
        for (ll i = 0, j = 0; uv.size() < 2; ++j, ++i) {
            if (j >= ai.size() or i != ai[j]) {
                uv.push_back(i);
                --j;
            }
        }
        u2v[uv[0]].push_back(uv[1]);
    }

    for (ll i = sum; i >= 0; --i) {
        if (u2v[i].size()) {
            mx = max(mx, dfs(dp, u2v, i, 0));
        }
    }

    for (ll i = 0; i <= min(sum, m); ++i) {
        ans += max(mx, dfs(dp, u2v, i, 1));
    }
    if (m > sum) {
        ans += ((m + sum + 1) * (m - sum) / 2LL);
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