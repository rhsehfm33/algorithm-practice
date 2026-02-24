#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n), sa(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sa[i] = i;
    }
    sort(sa.begin(), sa.end(), [&](ll l, ll r) {
        return a[l] > a[r] or (a[l] == a[r] and l > r);
    });
    for (auto i : sa) {
        for (ll i2 = 1; i2 <= a[i]; ++i2) {
            ll lj = i - a[i] * i2;
            if (lj >= 0 and i - lj == a[i] * a[lj]) {
                ++ans;
            }
            ll rj = i + a[i] * i2;
            if (i2 < a[i] and rj < n and rj - i == a[rj] * a[i]) {
                ++ans;
            }
            if (lj < 0 and rj >= n) {
                break;
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