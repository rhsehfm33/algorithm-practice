#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    vector<bool> ans(n + 1);
    for (int u = 1; u <= n; ++u) {
        set<int> s;
        for (int v : u2v[u]) {
            if (a[u] == a[v]) {
                ans[a[u]] = true;
            }
            if (s.count(a[v])) {
                ans[a[v]] = true;
            } else {
                s.insert(a[v]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << (ans[i] ? '1' : '0');
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