#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;
const ll MOD = 1e9 + 7;

vector<ll> f;

ll add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

void preset() {
    f.resize(2e5 + 1);
    f[0] = f[1] = 1;
    for (ll i = 2; i <= 2e5; ++i) {
        f[i] = mul(i, f[i - 1]);
    }
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

ll cp(ll all, ll sel) {
    return mul(mul(f[all], inv(f[all - sel])), inv(f[sel])) % MOD;
}

void solve() {
    ll n, k, c0 = 0, c1 = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        if (ai % 2) {
            ++c1;
        } else {
            ++c0;
        }
    }

    ll ans = 0;
    for (ll i = (k + 1) / 2; i <= min(k, c1); ++i) {
        if (c0 >= k - i) {
            ans = add(ans, mul(cp(c1, i), cp(c0, k - i)));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}