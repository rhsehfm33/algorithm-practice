#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll sum = 0;
    ll n, k;
    cin >> n >> k;
    vector<array<ll, 2>> ab(n);
    for (ll i = 0; i < 2; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> ab[j][i];
            if (i) {
                sum += abs(ab[j][0] - ab[j][1]);
            }
        }
    }
    sort(ab.begin(), ab.end());

    ll ans = 1e18;
    for (ll i = 1; i < n; ++i) {
        if (min(ab[i][0], ab[i][1]) <= max(ab[i - 1][0], ab[i - 1][1])) {
            cout << sum << '\n';
            return;
        }
        ll r1 = abs(ab[i][0] - ab[i][1]) + abs(ab[i - 1][0] - ab[i - 1][1]);
        ll r2 = ab[i][0] + ab[i][1] - ab[i - 1][0] - ab[i - 1][1];
        ans = min(ans, sum - r1 + r2);
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