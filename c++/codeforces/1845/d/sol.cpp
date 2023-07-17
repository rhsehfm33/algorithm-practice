#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0, cur = 0, mx = 0, org = 0;
    for (ll i = 0; i < n; ++i) {
        org += a[i];

        if (a[i] >= 0) {
            cur += a[i];
            mx = max(mx, org);
        }
        else {
            if (mx > cur + a[i]) {
                ans = mx;
                cur = mx;
            }
            else {
                cur += a[i];
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}