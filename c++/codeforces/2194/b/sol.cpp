#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, x, y, sum = 0;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += (ai / x) * y;
    }

    ll ans = 0;
    for (auto& ai : a) {
        ans = max(ans, sum + ai - (ai / x) * y);
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