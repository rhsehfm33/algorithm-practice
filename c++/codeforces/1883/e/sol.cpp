#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_lmb(ll num) {
    for (ll i = 32; i >= 0; --i) {
        if ((num >> i) & 1) {
            return i;
        }
    }
    return -1;
}

bool is_left_big(ll l, ll r) {
    ll l_lmb = get_lmb(l);
    ll r_lmb = get_lmb(r);
    if (l_lmb < r_lmb) {
        l <<= (r_lmb - l_lmb);
    } else if (r_lmb < l_lmb) {
        r <<= (l_lmb - r_lmb);
    }
    return l >= r;
}

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    for (ll i = 1, s = get_lmb(a[0]); i < n; ++i) {
        ll c_lmb = get_lmb(a[i]);
        bool cb = is_left_big(a[i], a[i - 1]);
        if (c_lmb > s or (c_lmb == s and cb)) {
            s = c_lmb;
            continue;
        }

        ans += s - c_lmb + (!cb);
        s += !cb;
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