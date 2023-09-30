#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll ans = 0, s2 = 0;
    for (ll i = n; i > 1; --i) {
        if (i % 2 == 0) {
            if (a[i] > 0) {
                s2 += a[i];
            }
            else {
                ans += s2;
                s2 = 0;
            }
        }
        else {
            if (a[i] > 0) {
                ans += a[i] + s2;
                s2 = 0;
            }
        }
    }

    if (s2) {
        ans += max(s2 - a[2], s2 + a[1]);
    }
    else {
        ans = max(ans, ans + a[1]);
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