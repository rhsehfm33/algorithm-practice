#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vi2 = vector<array<int, 2>>;

int _ti;

array<int, 2> set_max(vector<bool>& app, vvi& u2v, array<int, 3>& mx, int u, int p) {
    array<int, 2> d = {1, u};

    vi2 md;
    for (int v : u2v[u]) {
        if (v != p and app[v]) {
            md.push_back(set_max(app, u2v, mx, v, u));
            sort(md.begin(), md.end(), greater<>());
            if (md.size() > 2) {
                md.pop_back();
            }
        }
    }

    if (md.size()) {
        d[0] += md[0][0];
        d[1] = md[0][1];
        if (md.size() >= 2) {
            mx = max(mx, {md[0][0] + md[1][0] + 1, 
                    max(md[0][1], md[1][1]),
                    min(md[0][1], md[1][1])});
        } else if (md.size() == 1) {
            mx = max(mx, {md[0][0] + 1, max(u, md[0][1]), min(u, md[0][1])});
        }
    } else {
        mx = max(mx, {1, u, u});
    }
    return d;
}

bool dfs(vvi& u2v, vector<bool>& app, int u, int e) {
    app[u] = false;
    if (u == e) {
        return false;
    }
    for (int v : u2v[u]) {
        if (app[v] and !dfs(u2v, app, v, e)) {
            return false;
        }
    }
    return app[u] = true;
}

void solve() {
    int n;
    cin >> n;
    vector<bool> app(n + 1, true);
    vvi u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; ++i) {
        while (app[i]) {
            array<int, 3> mx = {1, i, i};
            set_max(app, u2v, mx, i, 0);
            ans.push_back(mx);
            dfs(u2v, app, mx[1], mx[2]);
        }
    }
    sort(ans.begin(), ans.end(), greater<>());
    for (auto [d, u, v] : ans) {
        cout << d << ' ' << u << ' ' << v << ' ';
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
