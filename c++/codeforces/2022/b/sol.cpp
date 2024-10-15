#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.rbegin(), a.rend());

    ll sum = a[0], over = a[0] * (x - 1);
    for (ll i = 1; i < n; ++i) {
        sum += a[i];
        over -= a[i];
    }
    if (over >= 0) {
        cout << a[0] << '\n';
        return;
    }
    cout << (sum + x - 1) / x << '\n';
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