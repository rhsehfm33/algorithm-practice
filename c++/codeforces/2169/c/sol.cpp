#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll ans = 0, s = 0;

    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
    }

    ans = s;
    for (ll l = 1, r = 1, sum = 0; r <= n; ++r) {
        sum += a[r];
        if ((r - l + 1) * (r + l) - sum > 0) {
            ans = max(ans, s + (r - l + 1) * (r + l) - sum);
        } else {
            l = r + 1;
            sum = 0;
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