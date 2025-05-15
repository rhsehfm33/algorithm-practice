#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void q1(ll n) {
    ll x, y;
    cin >> x >> y;

    ll ans = 1;
    for (ll cx = 1, cy = 1, hl = (1LL << n) / 2; hl; hl /= 2) {
        if (x >= cx + hl and y >= cy + hl) {
            ans += hl * hl;
            cx += hl;
            cy += hl;
        } else if (x >= cx + hl and y < cy + hl) {
            ans += hl * hl * 2;
            cx += hl;
        } else if (x < cx + hl and y >= cy + hl) {
            ans += hl * hl * 3;
            cy += hl;
        }
    }
    cout << ans << '\n';
}

void q2(ll n) {
    ll d;
    cin >> d;
    ll ax = 1, ay = 1, hl = (1LL << n) / 2;
    while (hl) {
        if (d > 3 * hl * hl) {
            ay += hl;
            d -= 3 * hl * hl;
        } else if (d > 2 * hl * hl) {
            ax += hl;
            d -= 2 * hl * hl;
        } else if (d > hl * hl) {
            ax += hl;
            ay += hl;
            d -= hl * hl;
        }
        hl /= 2;
    }
    cout << ax << ' ' << ay << '\n';
}

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string a;
        cin >> a;
        if (a == "->") {
            q1(n);
        } else {
            q2(n);
        }
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