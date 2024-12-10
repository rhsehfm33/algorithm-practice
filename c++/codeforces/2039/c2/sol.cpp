#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll x, m;
    cin >> x >> m;
    ll ans = -1;
    for (ll y = 1; y <= min(x - 1, m); ++y) {
        if ((x ^ y) % y == 0) {
            ++ans;
        }
    }

    ans += ((x ^ m) % x == 0);
    for (ll b = 1ll << 60, cb = 0; ; b >>= 1) {
        if (x & b) {
            cb |= b;
        }
        if (m & b) {
            ll lb = (cb + x - 1) / x;
            ll hb = (cb + b - 1) / x;
            ans += (hb - lb + 1);
            cb ^= b;
        }
        if (b == 0) {
            break;
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