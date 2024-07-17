#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, ans = 0, mxc = 0;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    for (ll i = 1, mx = a[0]; i < n; ++i) {
        if (a[i] < mx) {
            ans += mx - a[i];
            mxc = max(mxc, mx - a[i]);
        } else {
            mx = a[i];
        }
    }
    ans += mxc;

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