#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<array<ll, 2>> dif;
    for (ll i = 0, pi, ppi; i < n; ++i) {
        cin >> pi;
        if (i) {
            dif.push_back({abs(pi - ppi), i});
        }
        ppi = pi;
    }
    sort(dif.begin(), dif.end());

    ll ans = (n * n - n) / 2;
    set<ll> s = {0, n - 1};
    for (ll i = 1, j = 0; i <= n - 1; ++i) {
        cout << ans << ' ';
        while (j < dif.size() and dif[j][0] == i) {
            auto rit = s.lower_bound(dif[j][1]);
            ll rc = *rit - dif[j][1] + 1;
            ll lc = dif[j][1] - *prev(rit);
            ans -= rc * lc;
            s.insert(dif[j][1] - 1);
            s.insert(dif[j][1]);
            ++j;
        }
    }
    cout << '\n';
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