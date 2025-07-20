#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int _ti;

void solve() {
    ll ans = 0;

    ll n;
    cin >> n;
    vector<array<ll, 4>> a(n);
    for (auto& [a, b, c, d] : a) {
        cin >> a >> b >> c >> d;
        if (b > d) {
            ans += a + (b - d);
        } else if (a > c) {
            ans += (a - c);
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