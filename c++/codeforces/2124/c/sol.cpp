#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> b(n);
    for (auto& bi : b) {
        cin >> bi;
    }

    ll ans = 1;
    for (ll i = 0; i + 1 < n; ++i) {
        if (b[i + 1] % b[i]) {
            ans = lcm(ans, b[i] / gcd(b[i], b[i + 1]));
        }
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