#include <bits/stdc++.h>

using namespace std;

int _ti;

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (i + 1 < n) {
            ans = max(ans, min(a[i], a[i + 1]));
        }
        if (i + 2 < n) {
            ans = max(ans, a[i] + a[i + 1] + a[i + 2] - min({a[i], a[i + 1], a[i + 2]}) - max({a[i], a[i + 1], a[i + 2]}));
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