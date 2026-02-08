#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void simul(ll x, ll y, ll& mn, ll& p, ll& q) {
    ll target = 1LL << ((ll)log2(x & y) + 1);
    ll q1 = (y - (x & y)) | (target - 1 - ((x | y) % target));
    if (abs(y - q1) < mn) {
        mn = abs(y - q1);
        p = x;
        q = q1;
    }
    while (target < (1LL << 32) and ((target & x) | (target & y))) {
        target <<= 1;
    }
    ll q2 = (y | target) - (y % target);
    if (abs(y - q2) < mn) {
        mn = abs(y - q2);
        p = x;
        q = q2;
    }
}

void solve() {
    ll x, y;
    cin >> x >> y;
    ll mn = x & y, p = x, q = y - (x & y);
    if (mn) {
        simul(x, y, mn, p, q);
        simul(y, x, mn, q, p);
    }
    cout << p << ' ' << q << '\n';
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