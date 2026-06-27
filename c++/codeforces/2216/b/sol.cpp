#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll t, h, u;
    cin >> t >> h >> u;
    ll ans = (t + h + u) * 3;
    ll mn1 = min(t, u);
    ans -= mn1 * 2;
    t -= mn1;

    ll mn2 = min(t, h * 2);
    ans -= mn2;
    t -= mn2;

    ans -= max(0LL, t - 1);
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