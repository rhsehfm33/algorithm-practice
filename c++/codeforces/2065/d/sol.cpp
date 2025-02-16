#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto& ai : a) {
        ll sum = 0;
        for (auto& aij : ai) {
            cin >> aij;
            sum += aij;
        }
        ai.push_back(sum);
    }
    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return l.back() > r.back();
    });

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ans += a[i][j] * (n * m - i * m - j);
        }
    }
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