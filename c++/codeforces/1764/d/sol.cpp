#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 5000;

ll n;
ll MOD;
ll f[MAX + 1];
ll inv_num[MAX + 1];
ll inv_f[MAX + 1];

void set_inv_num() {
    inv_num[0] = inv_num[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        inv_num[i] = inv_num[MOD % i] * (MOD - MOD / i) % MOD;
    }
}

void set_inv_f() {
    inv_f[0] = inv_f[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        inv_f[i] = (inv_num[i] * inv_f[i - 1]) % MOD;
    }
}
 
void set_f() {
    f[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
}

ll get_combi(ll all, ll sel) {
    return f[all] * inv_f[all - sel] % MOD * inv_f[sel] % MOD;
}

ll mod_mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

ll mod_add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

void solve() {
    cin >> n >> MOD;

    set_inv_num();
    set_inv_f();
    set_f();

    ll ans = 0;
    if (n % 2 == 0) {
        for (ll l = 2; l <= n / 2; ++l) {
            for (ll x = 0; x <= l - 2; ++x) {
                ll op1 = l;
                ll op2 = f[n - 1 - (l - x)];
                ll op3 = get_combi(l - 2, x);
                ans = mod_add(ans, mod_mul(mod_mul(op1, op2), op3));
            }
        }
        ans = mod_mul(ans, n);
        ans = mod_add(ans, mod_mul(n, f[n - 2]));
        cout << ans << '\n';
    }
    else {
        for (ll l = 2; l <= n / 2 + 1; ++l) {
            for (ll x = 0; x <= l - 2; ++x) {
                ll op1 = l - 1;
                ll op2 = f[n - 1 - (l - x)];
                ll op3 = get_combi(l - 2, x);
                ans = mod_add(ans, mod_mul(mod_mul(op1, op2), op3));
            }
        }
        ans = mod_mul(ans, n);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}