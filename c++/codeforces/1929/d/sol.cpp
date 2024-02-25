#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int _ti;

array<ll, 3> fetch(vector<vector<int>>& u2v, int ci, int pi) {
    array<ll, 3> r = {1, 1, 0};
    for (int ni : u2v[ci]) {
        if (pi != ni) {
            auto cs = fetch(u2v, ni, ci);
            r[1] = (r[1] * (cs[1] + 1)) % MOD;
            r[2] = (r[2] + cs[1] + cs[2]) % MOD;
        }
    }

    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    array<ll, 3> root = fetch(u2v, 1, -1);

    cout << (root[0] + root[1] + root[2]) % MOD << '\n';
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