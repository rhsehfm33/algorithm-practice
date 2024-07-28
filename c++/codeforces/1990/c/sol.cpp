#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll go(vector<ll>& a) {
    ll sum = 0;
    vector<bool> v(a.size() + 1);
    for (ll i = 0, mx = 0; i < a.size(); ++i) {
        sum += a[i];
        if (v[a[i]]) {
            mx = max(mx, a[i]);
        } else {
            v[a[i]] = true;
        }
        a[i] = mx;
    }
    return sum;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = go(a) + go(a);
    for (ll i = 0; i < n; ++i) {
        ans += a[i] * (n - i);
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