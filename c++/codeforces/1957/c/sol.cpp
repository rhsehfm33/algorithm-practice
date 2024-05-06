#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

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

void solve() {
    ll n, k;
    cin >> n >> k;
    ll r = n, c = 1;
    while (k--) {
        ll ri, ci;
        cin >> ri >> ci;
        r = ri == ci ? r - 1 : r - 2;
    }

    ll ans = 1, rm = 1, cm = 1;
    while (r - 2 >= 0) {
        rm = mul(mul(rm, r), r - 1);
        cm = mul(cm, c);
        ans = add(ans, mul(rm, inv(cm)));
        c += 1;
        r -= 2;
    }
    cout << ans << '\n';
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