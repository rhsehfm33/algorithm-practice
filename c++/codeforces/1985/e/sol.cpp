#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll x, y, z, k, ans = 0;
    cin >> x >> y >> z >> k;
    for (ll kx = 1; kx <= x; ++kx) {
        for (ll ky = 1; ky <= y; ++ky) {
            ll kz = k / (kx * ky);
            if (kz <= z and kz * kx * ky == k) {
                ans = max(ans, (x - kx + 1) * (y - ky + 1) * (z - kz + 1));
            }
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