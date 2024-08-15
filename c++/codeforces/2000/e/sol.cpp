#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<ll> a(w);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<ll> cnts;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll l = max(0LL, j - k + 1);
            ll r = min(m - k, j);
            ll u = max(0LL, i - k + 1);
            ll d = min(n - k, i);
            cnts.push_back((r - l + 1) * (d - u + 1));
        }
    }

    ll ans = 0;
    sort(a.rbegin(), a.rend());
    sort(cnts.rbegin(), cnts.rend());
    for (ll i = 0; i < a.size(); ++i) {
        ans += a[i] * cnts[i];
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