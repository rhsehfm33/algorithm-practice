#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll diff = 0;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> ps(n + 1, vector<ll>(m + 1));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] + (ch == '0' ? 1 : -1) - ps[i - 1][j - 1];
            diff += (ch == '0' ? a[i][j] : -a[i][j]);
        }
    }
    diff = abs(diff);

    ll agcd = 0;
    for (ll i = k; i <= n; ++i) {
        for (ll j = k; j <= m; ++j) {
            ll cdiff = abs(ps[i][j] - ps[i - k][j] - ps[i][j - k] + ps[i - k][j - k]);
            if (cdiff) {
                agcd = gcd(agcd, cdiff);
            }
        }
    }

    if (agcd) {
        diff %= agcd;
    }

    cout << (diff ? "NO" : "YES") << '\n';
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