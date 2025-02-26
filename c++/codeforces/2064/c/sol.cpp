#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    vector<ll> ls(n), rs(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            ls[i] += a[i];
        }
        if (i) {
            ls[i] += ls[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < 0) {
            rs[i] += abs(a[i]);
        }
        if (i + 1 < n) {
            rs[i] += rs[i + 1];
        }
    }

    ll ans = max((a[0] < 0 ? rs[0] : 0ll), (a[n - 1] >= 0 ? ls[n - 1] : 0ll));
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] >= 0 and a[i] < 0) {
            ans = max(ans, ls[i - 1] + rs[i]);
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