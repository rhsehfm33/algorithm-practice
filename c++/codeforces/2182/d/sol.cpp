#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

int _ti;

vector<ll> fact, ifact, inv;

void init_fact(int n, ll mod) {
    fact.resize(n + 1);
    ifact.resize(n + 1);
    inv.resize(n + 1);

    fact[0] = ifact[0] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        if (i > 1) {
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        }
        ifact[i] = ifact[i - 1] * inv[i] % mod;
    }
}

void solve() {
    ll n, sum = 0, mx = -1, mcnt = 0, fi;
    cin >> n >> fi;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
        if (mx < ai) {
            mx = ai;
            mcnt = 1;
        } else if (mx == ai) {
            ++mcnt;
        }
    }

    ll ans = 1;
    ll space = n - max(0LL, (mx * n - sum) - fi);
    if (space < mcnt) {
        cout << "0\n";
        return;
    }
    cout << (fact[space] * ifact[space - mcnt] % MOD) * fact[n - mcnt] % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init_fact(55, MOD);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}