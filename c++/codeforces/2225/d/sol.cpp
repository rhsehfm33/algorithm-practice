#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __uint128_t;
 
const lll MOD = 998244353;
int _ti;
 
lll get_sum(lll n) {
    lll c1 = (n + 1) / 4;
    c1 = ((c1 + 1) * c1 / 2) % MOD;
 
    lll c2 = (n + 3) / 4 - 1;
    c2 = ((c2 + 1) * c2 / 2) % MOD;
 
    return (c1 + c2) % MOD;
}
 
void solve() {
    ll n, x;
    cin >> n >> x;
    lll ans = (get_sum(n) - get_sum(x - 1) + MOD) % MOD;
    for (ll tx = x + 1; tx <= x + 4 and tx <= n; ++tx) {
        if (tx % 2 == 0) {
            lll c = (n - tx + 1) / 4;
            c = ((c + 1) * c / 2) % MOD;
            ans = (ans - c + MOD) % MOD;
        }
    }
    cout << (ll)ans << '\n';
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