#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }
    for (ll i = n - 1; i > 0; --i) {
        if (a[i] > b[i]) {
            a[i - 1] += a[i] - b[i];
            a[i] = b[i];
        }
    }
    cout << (a[0] > b[0] ? "NO" : "YES") << '\n';
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