#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1; i <= n; ++i) {
        sum += i * (i * 2 - 1);
    }
    cout << sum << ' ' << 2 * n << '\n';
    for (ll i = n; i >= 1; --i) {
        cout << "1 " << i << ' ';
        for (ll j = 1; j <= n; ++j) {
            cout << j << ' ';
        }
        cout << '\n';
        cout << "2 " << i << ' ';
        for (ll j = 1; j <= n; ++j) {
            cout << j << ' ';
        }
        cout << '\n';
    }
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