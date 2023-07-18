#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ld getSmallerSpace(ld bd, ld bh, ld sh) {
    ld sd = bd * sh / bh;
    return sd * sh / 2;
}

void solve(int _ti) {
    ll n, d, h;
    cin >> n >> d >> h;

    ld ans = (ld)(d * h * n) / 2;

    for (ll i = 0, pyi = -2e9; i < n; ++i) {
        ll yi;
        cin >> yi;
        if (yi < pyi + h) {
            ans -= getSmallerSpace(d, h, pyi + h - yi);
        }
        pyi = yi;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(7);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}