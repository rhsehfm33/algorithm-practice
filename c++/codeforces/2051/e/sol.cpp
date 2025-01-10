#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    map<int, array<int, 2>> m;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        ++m[ai][0];
    }
    for (int i = 0, bi; i < n; ++i) {
        cin >> bi;
        ++m[bi][1];
    }

    ll ans = 0, cpo = n, cng = 0;
    for (auto [p, v] : m) {
        auto [ng, na] = v;
        if (cng <= k) {
            ans = max(ans, p * (cpo + cng));
        }
        cpo -= ng;
        cng += ng - na;
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