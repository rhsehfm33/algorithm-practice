#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> a(m), s(n + 1);
    for (auto& ai : a) {
        cin >> ai;
        ++s[ai];
    }

    for (int i = n - 1; i > 0; --i) {
        s[i] += s[i + 1];
    }
    for (int i = 1; i <= n; ++i) {
        s[i] += s[i - 1];
    }
    for (auto& ai : a) {
        ll mn = n - min(n - 1, ai);
        ll mx = n - 1;
        ans += s[mx] - s[mn - 1];
        ans -= max(0ll, min(n - 1, ai) - mn + 1);
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