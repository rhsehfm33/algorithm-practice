#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> q(n), r(n);
    for (auto& qi : q) {
        cin >> qi;
    }
    for (auto& ri : r) {
        cin >> ri;
    }

    ll ans = 0;
    sort(q.begin(), q.end());
    sort(r.begin(), r.end(), greater<ll>());
    for (ll qi = 0, ri = 0; ri < n; ++ri) {
        while (ri < n and (r[ri] + 1) * q[qi] + r[ri] > k) {
            ++ri;
        }
        if (ri < n) {
            ++qi;
            ++ans;
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