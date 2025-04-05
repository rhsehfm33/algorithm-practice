#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;
const ll MAX = 3e5;

int _ti;

vector<ll> f;
vector<ll> finv;

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


void preset_finv() {
    finv.resize(MAX + 1);
    finv[MAX] = inv(f[MAX]);
    for (ll i = MAX - 1; i >= 1; --i) {
        finv[i] = (finv[i + 1] * (i + 1)) % MOD;
    }
    finv[0] = 1;
}

void preset() {
    f.resize(MAX + 1);
    f[0] = 1;
    for (ll i = 1, c = 1; i <= MAX; ++i) {
        c = (c * i) % MOD;
        f[i] = c;
    }
    preset_finv();
}

ll com(ll a, ll s) {
    return (((f[a] * finv[a - s]) % MOD) * finv[s]) % MOD;
}


void solve() {
    ll n = 0;
    vector<ll> c(26);
    for (auto& ci : c) {
        cin >> ci;
        n += ci;
    }

    ll cnt = 0;
    ll cn = 0;
    ll en = n / 2;
    ll on = n / 2 + n % 2;
    vector<ll> dp(en + 1);
    dp[0] = 1;
    for (auto ci : c) {
        if (ci == 0) {
            continue;
        }
        vector<ll> dp2(en + 1);
        for (ll i = 0; i <= min(cn, en); ++i) {
            ll ec = en - i;
            if (ci <= ec) {
                dp2[i + ci] = (dp2[i + ci] + (dp[i] * com(ec, ci)) % MOD) % MOD;
            }
            ll oc = on - (cn - i);
            if (ci <= oc) {
                dp2[i] = (dp2[i] + (dp[i] * com(oc, ci)) % MOD) % MOD;
            }
        }
        swap(dp, dp2);
        cn += ci;
    }

    cout << dp[en];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
        cout << '\n';
    }

    return 0;
}