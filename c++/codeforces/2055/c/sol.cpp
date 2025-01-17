#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> rs(n), cs(m);

    string s;
    cin >> s;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> a[i][j];
            rs[i] += a[i][j];
            cs[j] += a[i][j];
        }
    }

    for (ll i = 0, x = 0, y = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
            a[x][y] -= cs[y];
            rs[x] -= cs[y];
            ++y;
        } else {
            a[x][y] -= rs[x];
            cs[y] -= rs[x];
            ++x;
        }
    }
    a[n - 1][m - 1] -= rs[n - 1];

    for (auto& ai : a) {
        for (auto& aij : ai) {
            cout << aij << ' ';
        }
        cout << '\n';
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