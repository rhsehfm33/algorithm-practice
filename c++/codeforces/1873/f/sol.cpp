#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll ans = 0;
    for (ll l = 0, r = 0, as = 0; r < n; ++r) {
        if (r == 0 or h[r - 1] % h[r] == 0) {
            as += a[r];
        }
        else {
            as = a[r];
            l = r;
        }

        while (l <= r and as > k) {
            as -= a[l++];
        }
        ans = max(ans, r - l + 1);
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