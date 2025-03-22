#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> b(2 * n);
    for (auto& bi : b) {
        cin >> bi;
        ans += bi;
    }
    sort(b.begin(), b.end());
    for (ll i = 0; i < n - 1; ++i) {
        ans -= b[i] * 2;
    }
    for (ll i = 0, l = 0, r = n * 2 - 1; i < 2 * n + 1; ++i) {
        if (i == 1) {
            cout << ans << ' ';
        } else if (i % 2 == 0) {
            cout << b[r--] << ' ';
        } else {
            cout << b[l++] << ' ';
        }
    }
    cout << '\n';
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