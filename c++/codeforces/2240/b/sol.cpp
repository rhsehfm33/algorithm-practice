#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const ll MOD = 998244353;
int _ti;

void solve() {
    ll n, m, r, c, ans = 1;
    cin >> n >> m >> r >> c;
    ll p2 = r * c - 1 + (r - 1) * (m - c) + (c - 1) * (n - r);
    for (ll i = 0, p = 2; i < 63; ++i) {
        if (p2 & ((ll)1 << i)) {
            ans = (ans * p) % MOD;
        }
        p = (p * p) % MOD;
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