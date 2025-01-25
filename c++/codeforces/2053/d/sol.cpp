#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int _ti;

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

ll inv(ll num) {
    ll result = 1;
    ll exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * num) % MOD;
        }
        num = (num * num) % MOD;
        exp /= 2;
    }
    return result;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> ab(2, vector<ll>(n)), i2ab(2, vector<ll>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ab[i][j];
            i2ab[i][j] = ab[i][j];
        }
    }

    ll p = 1;
    sort(ab[0].begin(), ab[0].end());
    sort(ab[1].begin(), ab[1].end());
    for (int i = 0; i < n; ++i) {
        p = mul(p, min(ab[0][i], ab[1][i]));
    }
    cout << p << ' ';

    while (q--) {
        int o, x;
        cin >> o >> x;
        --o;
        --x;
        int i = prev(upper_bound(ab[o].begin(), ab[o].end(), i2ab[o][x])) - ab[o].begin();
        p = mul(p, inv(min(ab[0][i], ab[1][i])));
        ++i2ab[o][x];
        ++ab[o][i];
        p = mul(p, min(ab[0][i], ab[1][i]));
        cout << p << ' ';
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