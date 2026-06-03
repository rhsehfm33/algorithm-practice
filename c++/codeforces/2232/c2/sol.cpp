#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, x, s;
    string u;
    cin >> n >> x >> s >> u;

    ll ans = 0;
    vector<ll> xs(x);
    for (ll i = 0, ii = 0, ei = 0, ac = 0; i < n and ei < x; ++i) {
        if (u[i] == 'A') {
            ac += (xs[ei] != 0);
            ++xs[ei];
            ++ans;
        } else if (u[i] == 'I' and ii < x) {
            ++xs[ii];
            ++ans;
        } else if (u[i] == 'E' and s > 1) {
            if (xs[ei] == 0 and ac) {
                ++xs[ei];
                ++ans;
                --ac;
            } else if (xs[ei]) {
                ++xs[ei];
                ++ans;
            }
        }

        while (ei < x and xs[ei] == s) {
            ++ei;
        }
        while (ii < x and xs[ii]) {
            ++ii;
        }
    }

    cout << min(x * s, ans) << '\n';
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