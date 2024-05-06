typedef long long ll;

const ll MOD = 1e9 + 7;

ll add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

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