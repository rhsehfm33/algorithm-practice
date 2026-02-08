// sol.cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> fact, ifact;

void init_fact(int n, ll mod) {
    fact.resize(n + 1);
    ifact.resize(n + 1);
    vector<ll> inv(n +1);

    fact[0] = ifact[0] = 1;
    inv[1] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        if (i > 1) {
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        }
        ifact[i] = ifact[i - 1] * inv[i] % mod;
    }
}

ll nCk(int n, int k, ll mod) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int main() {
    const ll MOD = 1'000'000'007;
    int N = 1'000'000;

    init_fact(N, MOD);
    cout << nCk(5, 2, MOD) << "\n"; // 10
}
