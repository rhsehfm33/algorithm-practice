#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> p = {2, 3, 5, 7};
int _ti;

ll get_sum(ll num) {
    ll sum = 0;
    for (ll i = 1; i < (1 << 4); ++i) {
        ll m = 1, c = 0;
        for (ll j = 0; j < 4; ++j) {
            if ((i >> j) & 1) {
                m *= p[j];
                ++c;
            }
        }
        if (c % 2) {
            sum += num / m;
        } else {
            sum -= num / m;
        }
    }
    return sum;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << (r - l + 1) - (get_sum(r) - get_sum(l - 1)) << '\n';
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