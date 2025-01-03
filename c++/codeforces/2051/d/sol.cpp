#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll sum = 0;

    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    ll mn = sum - y;
    ll mx = sum - x;
    for (ll r = n - 1, l = 0, m = 0; r; --r) {
        m = min(m, r);
        while (m < r and a[m] + a[r] <= mx) {
            ++m;
        }
        l = min(l, m);
        while (l < m and a[l] + a[r] < mn) {
            ++l;
        }
        ans += (m - l);
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