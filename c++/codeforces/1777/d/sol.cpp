#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll mod_add(ll num1, ll num2) {
    return (num1 + num2) % MOD;
}

ll mod_mul(ll num1, ll num2) {
    return (num1 * num2) % MOD;
}

ll get_mod_pow_of2 (ll power) {
    ll result = 1;
    for (ll i = 0, mul = 2; (1 << i) <= power; ++i) {
        if ((power >> i) & 1) {
            result = mod_mul(result, mul);
        }
        mul = mod_mul(mul, mul);
    }
    return result;
}

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    vector<bool> vis(n + 1);
    vis[1] = true;
    queue<int> q;
    q.push(1);
    queue<int> q2;
    while (q.size()) {
        int ql = q.size();
        while (ql--) {
            int u = q.front(); q.pop();
            if (u != 1 and u2v[u].size() == 1) {
                q2.push(u);
                continue;
            }

            for (auto v : u2v[u]) {
                if (vis[v] == false) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    vector<int> ind(n + 1);
    ind[1] = u2v[1].size();
    for (int i = 2; i <= n; ++i) {
        ind[i] = u2v[i].size() - 1;
    }

    vector<ll> alive = {n};
    while (q2.size()) {
        int ql = q2.size();
        alive.push_back(alive.back() - ql);
        while (ql--) {
            int u = q2.front(); q2.pop();
            for (auto v : u2v[u]) {
                if (--ind[v] == 0) {
                    q2.push(v);
                }
            }
        }
    }

    ll ans = 0;
    ll case1 = get_mod_pow_of2(n - 1);
    for (int i = 0; i < alive.size(); ++i) {
        ll result = mod_mul(case1, alive[i]);
        ans = mod_add(ans, result);
    }

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