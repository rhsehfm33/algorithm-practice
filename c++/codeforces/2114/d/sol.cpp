#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    map<ll, ll> mx, my;
    ll n;
    cin >> n;
    vector<array<ll, 2>> xy(n);
    for (auto& [x, y] : xy) {
        cin >> x >> y;
        ++mx[x];
        ++my[y];
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }

    ll ans = 2e18;
    for (auto& [x, y] : xy) {
        ll sx = mx.begin()->first;
        ll bx = mx.rbegin()->first;
        ll sy = my.begin()->first;
        ll by = my.rbegin()->first;
        if (sx == x and mx[sx] == 1) {
            sx = next(mx.begin())->first;
        }
        if (bx == x and mx[bx] == 1) {
            bx = next(mx.rbegin())->first;
        }
        if (sy == y and my[sy] == 1) {
            sy = next(my.begin())->first;
        }
        if (by == y and my[by] == 1) {
            by = next(my.rbegin())->first;
        }
        ll sz = (bx - sx + 1) * (by - sy + 1);
        sz = sz >= n ? sz : sz + min(bx - sx + 1, by - sy + 1);
        ans = min(ans, sz);
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