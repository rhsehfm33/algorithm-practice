#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll c0 = 0, c1 = 0;

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2) {
            c1 += a[i];
        } else {
            c0 += a[i];
        }
    }

    if (c0 % ((n + 1) / 2) == 0 and c1 % (n / 2) == 0
    and c0 / ((n + 1) / 2) == c1 / (n / 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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