#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll sum = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += (i % 2 ? -a[i] : a[i]);
    }

    ll ans = sum;
    vector<ll> x = {(ll)-1e15, (ll)-1e15};
    for (ll i = 0; i < n; ++i) {
        ll d = i % 2;
        if (d) {
            ll sum1 = sum + (i - 1);
            ll sum2 = sum + a[i] * 2 + i + x[d ^ 1];
            ans = max({ans, sum1, sum2});
            x[d] = max(x[d], a[i] * 2 - i);
        } else {
            ll sum1 = sum + i;
            ll sum2 = sum - a[i] * 2 + i + x[d ^ 1];
            ans = max({ans, sum1, sum2});
            x[d] = max(x[d], -a[i] * 2 - i);
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