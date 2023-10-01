#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll a, b, n;
    cin >> a >> b >> n;

    ll ans = b;
    for (ll i = 0; i < n; ++i) {
        ll xi;
        cin >> xi;
        ans += min(a - 1, xi);
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