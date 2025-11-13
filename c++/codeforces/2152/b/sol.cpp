#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    ll ans = 0;
    if (rk > rd) {
        ans = max(ans, n - rd);
    } else if (rk < rd) {
        ans = max(ans, rd);
    }
    if (ck > cd) {
        ans = max(ans, n - cd);
    } else if (ck < cd) {
        ans = max(ans, cd);
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