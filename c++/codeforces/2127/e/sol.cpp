#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n), s(n);
    for (auto& pi : p) {
        cin >> pi;
    }
    for (auto& si : s) {
        cin >> si;
    }

    int ans = 1;
    for (ll i = 0; i < n and ans; ++i) {
        ll m = lcm(p[i], s[i]);
        if (i == 0) {
            ans &= (p[i] == m);
        } else {
            ans &= (gcd(m, p[i - 1]) == p[i]);
        }
        if (i == n - 1) {
            ans &= (s[i] == m);
        } else {
            ans &= (gcd(m, s[i + 1]) == s[i]);
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
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