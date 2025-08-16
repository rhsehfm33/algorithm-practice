#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    vector<vector<array<ll, 2>>> u2v(n + 1);
    for (ll i = 0, u, v, c; i < n - 1; ++i) {
        cin >> u >> v >> c;
        u2v[u].push_back({v, c});
        u2v[v].push_back({u, c});
        if (a[u] != a[v]) {
            ans += c;
        }
    }

    vector<map<ll, ll>> cs(n + 1);
    vector<array<ll, 2>> par(n + 1, {0, 0});
    auto set_tree = [&](auto&& self, ll u, ll p) -> void {
        for (auto [v, c] : u2v[u]) {
            if (v != p) {
                cs[u][a[v]] += c;
                par[v] = {u, c};
                self(self, v, u);
            }
        }
    };
    set_tree(set_tree, 1, 0);

    while (q--) {
        ll u, x;
        cin >> u >> x;
        auto [p, pc] = par[u];

        ans += cs[u][a[u]];
        if (a[p] == a[u]) {
            ans += pc;
        }
        cs[p][a[u]] -= pc;

        a[u] = x;
        ans -= cs[u][a[u]];
        if (a[p] == a[u]) {
            ans -= pc;
        }
        cs[p][a[u]] += pc;
        cout << ans << '\n';
    }
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