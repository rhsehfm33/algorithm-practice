#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int _ti;

void solve() {
    ll n, k, ans = 1;
    cin >> n >> k;
    vector<ll> l(n), r(n), s(n);
    for (auto& li : l) {
        cin >> li;
    }
    for (auto& ri : r) {
        cin >> ri;
    }
    for (ll i = 0; i < n; ++i) {
        ans += max(l[i], r[i]);
        s[i] = min(l[i], r[i]);
    }
    sort(s.begin(), s.end(), greater<ll>());
    ans += accumulate(s.begin(), s.begin() + k - 1, 0ll);
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