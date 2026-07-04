#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

ll dfs(vector<vector<int>>& u2v, vector<int>& a, ll& ans, int u, int p, ll n) {
    ll res = 1;
    vector<ll> s;
    for (int v : u2v[u]) {
        if (v != p) {
            s.push_back(dfs(u2v, a, ans, v, u, n));
            res += s.back();
        }
    }
    if (a[u] == -1 or s.empty()) {
        return res;
    }
    if (n - res > 0) {
        s.push_back(n - res);
    }

    ans += (n - 1) * (n - 2) / 2;
    ans += (n - 1) * (n - 2) * (n - 3) / 6;
    for (auto si : s) {
        if (si >= 2) {
            ll c2 = (si * (si - 1)) / 2;
            ans -= c2;
            ans -= c2 * (n - 1 - si);
        }
        if (si >= 3) {
            ans -= (si * (si - 1) * (si - 2)) / 6;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ll r = llround(sqrt((double)a[i]));
        if (r * r != a[i]) {
            a[i] = -1;
        }
    }
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    ll ans = 0;
    dfs(u2v, a, ans, 1, 0, n);
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