#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> d;
    for (ll cn = n; cn; cn /= 3) {
        if (k - cn % 3 < 0) {
            cout << "-1\n";
            return;
        }
        k -= cn % 3;
        d.push_back(cn % 3);
    }
    for (ll i = d.size() - 1; i > 0 and k >= 2; --i) {
        ll div = min(k / 2, d[i]);
        d[i] -= div;
        d[i - 1] += div * 3;
        k -= div * 2;
    }

    ll ans = d[0] * 3;
    for (ll i = 1, x = 3; i < d.size(); ++i, x *= 3) {
        ans += (x * 3 + i * (x / 3)) * d[i];
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