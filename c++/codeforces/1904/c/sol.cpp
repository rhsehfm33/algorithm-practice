#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    
    ll ans = a[n - 1];
    sort(a.begin(), a.end());
    if (k >= 1) {
        for (ll i = 0; i < n - 1; ++i) {
            ans = min({ans, a[i], abs(a[i + 1] - a[i])});
        }
    }
    if (k == 2) {
        for (ll i = 0; i < n - 1; ++i) {
            for (ll j = i + 1; j < n; ++j) {
                ll d = abs(a[i] - a[j]);
                auto it = lower_bound(a.begin(), a.end(), d);
                if (it != a.end()) {
                    ans = min(ans, abs(*it - d));
                }
                if (it != a.begin()) {
                    ans = min(ans, abs(*prev(it) - d));
                }
            }
        }
    }
    if (k >= 3) {
        ans = 0;
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