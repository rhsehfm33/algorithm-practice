typedef long long ll;

const ll MOD = 1e9 + 7;

ll addup(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

ll inv(ll n) {
    ll r = 1;
    ll e = MOD - 2;
    while (e > 0) {
        if (e % 2 == 1) {
            r = (r * n) % MOD;
        }
        n = (n * n) % MOD;
        e /= 2;
    }
    return r;
}