#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    ll ab = gcd(a, b), ans = 1e18;
    vector<ll> r;
    while (n--) {
        ll ci; cin >> ci;
        r.push_back(ci % ab);
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    for (ll i = 0; r[i] < ab; ++i) {
        r.push_back(r[i] + ab);
    }
    for (ll li = 0, ri = 0; ri < r.size(); ++ri) {
        if (r[li] + ab > r[ri]) {
            continue;
        }
        while (r[li] + ab <= r[ri]) {
            ++li;
        }
        ans = min(ans, r[ri] - r[li]);
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