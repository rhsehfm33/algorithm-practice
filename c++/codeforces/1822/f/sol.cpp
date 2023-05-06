#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_max_path(vector<vector<ll>>& u2v, ll& ans, ll p, ll u, ll depth, const ll k, const ll c) {
    ll max_path1 = 0;
    ll max_path2 = 0;
    for (ll v : u2v[u]) {
        if (v == p) {
            continue;
        }

        ll v_max_path = 1 + get_max_path(u2v, ans, u, v, depth + 1, k, c);
        if (max_path1 < v_max_path) {
            max_path2 = max_path1;
            max_path1 = v_max_path;
        }
        else if(max_path2 < v_max_path) {
            max_path2 = v_max_path;
        }
    }

    ll profit = (max_path1 + max_path2) * k - (depth + max_path2) * c;
    ans = max(ans, profit);
    if (u == 1) {
        ans = max(ans, max_path1 * k);
    }

    return max_path1;
}

void solve(int _ti) {
    ll n, k, c;
    cin >> n >> k >> c;

    vector<vector<ll>> u2v(n + 1);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    ll ans = 0;
    get_max_path(u2v, ans, -1, 1, 0, k, c);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}