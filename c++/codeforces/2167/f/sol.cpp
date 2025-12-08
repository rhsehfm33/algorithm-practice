#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    ll ans = n;
    auto dfs = [&](auto self, int u, int p) -> int {
        int sum = 0;
        vector<int> cnt;
        for (int v : u2v[u]) {
            if (v != p) {
                cnt.push_back(self(self, v, u));
                sum += cnt.back();
            }
        }
        cnt.push_back(n - sum - 1);
        for (int ci : cnt) {
            if (n - ci >= k) {
                ans += ci;
            }
        }

        return sum + 1;
    };
    dfs(dfs, 1, 0);
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