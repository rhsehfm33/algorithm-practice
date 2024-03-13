#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    array<ll, 2> r = {0, 0};
    ll n, c, si;
    cin >> n >> c;
    vector<ll> s(n);
    for (auto& si : s) {
        cin >> si;
        ++r[si % 2];
    }

    ll ans = (c + 2) * (c + 1) / 2;
    for (auto& si : s) {
        ans -= (si / 2 + 1 + c - si);
        ans += --r[si % 2];
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