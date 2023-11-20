#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    for (ll i = n - 2, prv = a[n - 1]; i >= 0; --i) {
        if (a[i] <= prv) {
            prv = a[i];
        } else if (a[i] % prv == 0) {
            ans += a[i] / prv - 1;
        } else {
            ans += a[i] / prv;
            ll low = a[i] % prv, high = prv - 1;
            while (low <= high) {
                ll mid = (low + high) / 2;
                if (mid * (a[i] / prv + 1) <= a[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            prv = low - 1;
        }
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