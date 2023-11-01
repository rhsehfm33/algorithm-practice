#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    map<ll, array<ll, 2>> m;

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (m.count(a[i]) == 0) {
            m[a[i]] = {(ll)2e9, (ll)-2e9};
        }
        m[a[i]][0] = min(m[a[i]][0], i);
        m[a[i]][1] = max(m[a[i]][1], i);
    }

    ll ans = 0;
    for (ll i = n - 1, lc = 0; i >= 0; --i) {
        if (i == m[a[i]][1]) {
            ++lc;
        }
        if (i == m[a[i]][0]) {
            ans += lc;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}