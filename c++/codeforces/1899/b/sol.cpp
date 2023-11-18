#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if (n % i) {
            continue;
        }

        ll mx = -1;
        ll mn = 1e18;
        for (int j = 0; j < n / i; ++j) {
            ll sum = accumulate(a.begin() + j * i, a.begin() + (j + 1) * i, 0ll);
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        ans = max(ans, mx - mn);
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