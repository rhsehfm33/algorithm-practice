#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, sum = 0, mn = 2e9;
    cin >> n;
    vector<ll> a(n), b(n + 1);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    for (ll i = 0; i < n; ++i) {
        ll l = min(a[i], b[i]);
        ll g = max(a[i], b[i]);
        if (b[n] >= l and b[n] <= g) {
            mn = min(mn, 0LL);
        } else {
            mn = min({mn, abs(l - b[n]), abs(g - b[n])});
        }
        sum += abs(a[i] - b[i]);
    }

    cout << sum + mn + 1 << '\n';
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