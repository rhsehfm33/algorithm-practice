#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll ans = 0;

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    ll mn = 2e9, mx = -1;
    for (ll i = 0; i < n; ++i) {
        ans += abs(a[i] - b[i]);
        ll big = max(a[i], b[i]);
        ll small = min(a[i], b[i]);
        mn = min(mn, big);
        mx = max(mx, small);
    }
    cout << max(ans, ans + (mx - mn) * 2) << '\n';
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