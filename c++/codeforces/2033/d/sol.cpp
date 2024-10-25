#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, ans = 0;
    cin >> n;
    map<ll, ll> m;
    m[0] = -1;
    for (ll i = 0, sum = 0, r = -1; i < n; ++i) {
        ll ai; cin >> ai;
        sum += ai;
        if (m.count(sum) and m[sum] >= r) {
            ++ans;
            r = i;
        }
        m[sum] = i;
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