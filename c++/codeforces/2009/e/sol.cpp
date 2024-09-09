#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll sum(ll s, ll e) {
    return (s + e) * (e - s + 1) / 2;
}

void solve() {
    ll n, k; cin >> n >> k;
    ll l = k, h = k + n - 1, e = k + n - 1;
    while (l <= h) {
        ll m = (l + h) / 2;
        ll s1 = sum(k, m);
        ll s2 = m + 1 <= e ? sum(m + 1, e) : 0;
        if (s1 <= s2) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    ll ans = sum(k, l - 1) - sum(l, e);
    ans = min(abs(ans), abs(ans + l + l));
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