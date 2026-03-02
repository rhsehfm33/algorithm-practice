#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll s, m;
    cin >> s >> m;
    if ((s & (~s + 1)) < (m & (~m + 1))) {
        cout << "-1\n";
        return;
    }

    ll l = 1, h = 1e18 + 5;
    while (l <= h) {
        ll mid = (l + h) / 2;
        ll s2 = s;
        for (ll i = (1LL << 59); i and s2; i >>= 1) {
            if (m & i) {
                s2 -= i * min(s2 / i, mid);
            }
        }
        if (s2 == 0) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << h + 1 << '\n';
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