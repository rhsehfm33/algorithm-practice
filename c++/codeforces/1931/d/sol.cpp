#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    map<array<ll, 2>, ll> m;
    for (auto ai : a) {
        ll cx = (x - (ai % x)) % x;
        ll cy = ai % y;
        ans += m[{cx, cy}];
        ++m[{ai % x, ai % y}];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}