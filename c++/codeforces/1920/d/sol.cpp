#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 2e18;

void solve(int _ti) {
    ll cs = 0;
    map<ll, ll> k2x;
    vector<ll> sz;

    ll n, q;
    cin >> n >> q;
    while (n--) {
        ll b, x;
        cin >> b >> x;
        if (cs == -1) {
            continue;
        }

        if (b == 1) {
            k2x[cs++] = x;
        } else {
            sz.push_back(cs);
            __int128_t tcs = cs;
            __int128_t tx = x;
            if (tcs + tcs * x <= MAX) {
                cs += cs * x;
            } else {
                cs = -1;
            }
        }
    }

    while (q--) {
        vector<ll> tsz = sz;

        ll k;
        cin >> k;
        --k;
        while (!k2x.count(k)) {
            k %= tsz.back();
            tsz.pop_back();
        }
        cout << k2x[k] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}