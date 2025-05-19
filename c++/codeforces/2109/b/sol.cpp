#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

ll help(ll n) {
    ll c = 0;
    while (n > 1) {
        n = (n + 1) / 2;
        ++c;
    }
    return c;
}


void solve() {
    ll n, m, a, b, ans = 0;
    cin >> n >> m >> a >> b;
    ans = help(n - a + 1) + help(m);
    ans = min(ans, help(b) + help(n));
    ans = min(ans, help(a) + help(m));
    ans = min(ans, help(m - b + 1) + help(n));
    cout << 1 + ans << '\n';
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