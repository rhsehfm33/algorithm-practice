#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> x(n);
    for (auto& xi : x) {
        cin >> xi;
    }

    map<ll, ll> m;
    for (ll i = 0; i < n - 1; ++i) {
        m[(i + 1) * (n - i - 1)] += x[i + 1] - x[i] - 1;
        ++m[(i + 1) * (n - i - 1) + i];
    }
    ++m[n - 1];

    while (q--) {
        ll k; cin >> k;
        cout << m[k] << ' ';
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