#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

ll get_cnt(ll num) {
    ll cnt = 0;
    for (ll i = 1; i <= num; i *= 10) {
        cnt += (num - (i - 1));
    }
    return cnt;
}

void solve() {
    ll k;
    cin >> k;
    ll l = 1, h = min((ll)1e14, k);
    while (l <= h) {
        ll m = (l + h) / 2;
        ll cnt = get_cnt(m);
        if (cnt < k) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    ll ans = 0;
    string ns = to_string(l);
    reverse(ns.begin(), ns.end());
    for (ll i = 0, j = 1; i < ns.size(); ++i, j *= 10) {
        for (ll k = 1; k <= 9; ++k) {
            ll d = ns[i] - '0';
            ll c = (l / (j * 10)) * j;
            if (k < d) {
                c += j;
            } else if (k == d) {
                c += (l % j + 1);
            }
            ans += c * k;
        }
    }

    ll cnt = get_cnt(l);
    for (ll i = 0; cnt - i > k; ++i) {
        ans -= (ns[i] - '0');
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