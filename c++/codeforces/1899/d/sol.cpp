#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    map<ll, ll> m;
    while (n--) {
        ll ai;
        cin >> ai;
        ++m[ai];
    }

    ll ans = 0;
    for (auto& [ai, cnt] : m) {
        if (ai == 2) {
            ans += cnt * m[1];
        }
        ans += cnt * (cnt - 1) / 2;
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