#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    for (ll i = 0, pd = 0, cu = 0, cd = 0; i < n; ++i) {
        if (s[i] == '1') {
            ans = max({ans, pd + cu, cd + 1});
            pd = cd + 1;
            cu = cd = 0;
        } else {
            cu += i;
            cd += n - i - 1;
            if (i == n - 1) {
                ans = max({ans, pd + cu, cd});
            }
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