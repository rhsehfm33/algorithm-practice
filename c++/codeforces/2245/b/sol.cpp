#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    sort(a.begin(), a.end(), greater<ll>());
    for (ll i = 0; i < n; ++i) {
        if (i < (n + 1) / 2 or a[i] > c) {
            ans += a[i] - c;
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