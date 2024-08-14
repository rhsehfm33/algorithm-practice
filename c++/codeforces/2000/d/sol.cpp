#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> ps(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }
    string s;
    cin >> s;
    s = " " + s;

    ll ans = 0;
    for (ll l = 1, r = n; l < r; --r) {
        if (s[r] != 'R') {
            continue;
        }
        while (l < r and s[l] != 'L') {
            ++l;
        }
        if (l < r) {
            ans += ps[r] - ps[l - 1];
            ++l;
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