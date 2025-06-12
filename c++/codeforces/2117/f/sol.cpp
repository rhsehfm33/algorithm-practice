#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvi = vector<vector<int>>;
 
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
int _ti;
vector<ll> ps(MAX);
 
void preset() {
    ps[0] = 1;
    for (ll i = 1; i < MAX; ++i) {
        ps[i] = (ps[i - 1] * 2) % MOD;
    }
}
 
void uvset(vvi& pu2v, vvi& u2v, int u, int p) {
    for (int v : pu2v[u]) {
        if (v != p) {
            u2v[u].push_back(v);
            uvset(pu2v, u2v, v, u);
        }
    }
}
 
int go(vvi& u2v, int u, int d) {
    if (u2v[u].size() == 0) {
        return 1;
    } else if (u2v[u].size() == 1) {
        return 1 + go(u2v, u2v[u][0], d + 1);
    }
 
    int r1 = go(u2v, u2v[u][0], d + 1);
    int r2 = go(u2v, u2v[u][1], d + 1);
    int r = max(r1, r2) - min(r1, r2);
    if (r == 0) {
        cout << (ps[d] * 2) % MOD << '\n';
    } else {
        cout << (ps[r + d] + ps[r + d - 1]) % MOD << '\n';
    }
    return 0;
}
 
void solve() {
    int n;
    cin >> n;
    vvi pu2v(n + 1), u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        pu2v[u].push_back(v);
        pu2v[v].push_back(u);
    }
    uvset(pu2v, u2v, 1, 0);
 
    int lc = 0;
    for (int i = 1; i <= n; ++i) {
        lc += u2v[i].empty();
    }
    if (lc > 2) {
        cout << "0\n";
    } else if (lc == 1) {
        cout << ps[n] << '\n';
    } else {
        go(u2v, 1, 1);
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preset();
 
    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }
 
    return 0;
}