#include <bits/stdc++.h>

using namespace std;

int _ti;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 2>> ac(n);
    for (auto& aci : ac) {
        cin >> aci[0];
    }
    for (auto& aci : ac) {
        cin >> aci[1];
    }

    ll ans = 0;
    sort(ac.begin(), ac.end());
    for (ll i = 0; i < n; ++i) {
        ll r1 = min(ac[i][1], m / ac[i][0]);
        ll s1 = ac[i][0] * r1;
        ans = max(ans, s1);
        if (i + 1 < n and ac[i][0] + 1 == ac[i + 1][0]) {
            ll r2 = min(ac[i + 1][1], (m - s1) / ac[i + 1][0]);
            ll s2 = ac[i + 1][0] * r2;
            ll mxr = min({m - s1 - s2, r1, ac[i + 1][1] - r2});
            ans = max(ans, s1 + s2 + mxr);
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