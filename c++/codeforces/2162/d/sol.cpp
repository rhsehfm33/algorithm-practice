#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

ll query(ll t, ll l, ll r) {
    ll result;
    cout << t << " " << l << " " << r << endl;
    cin >> result;
    return result;
}

void solve() {
    ll n;
    cin >> n;
    ll d = query(2, 1, n) - (n + 1) * n / 2LL;

    ll l = 1, h = n;
    while (l <= h) {
        ll m = (l + h) / 2;
        ll r = query(2, 1, m) - query(1, 1, m);
        if (r) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << "! " << h + 1 << " " << h + d << endl;
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