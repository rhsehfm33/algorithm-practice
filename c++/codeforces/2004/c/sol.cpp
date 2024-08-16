#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    sort(a.begin(), a.end());
    for (ll i = n - 1; i > 0; i -= 2) {
        ans += (a[i] - a[i - 1]);
        ans -= min(k, a[i] - a[i - 1]);
        k -= min(k, a[i] - a[i - 1]);
    }
    if (n % 2) {
        ans += a[0];
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