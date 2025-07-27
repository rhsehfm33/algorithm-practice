#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

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

ll add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

ll mdiv(ll n1, ll n2) {
    return mul(n1, inv(n2));
}


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<array<ll, 3>>> prob(m + 1);
    for (ll i = 0, l, r, p, q; i < n; ++i) {
        cin >> l >> r >> p >> q;
        prob[l].push_back({r, p, q});
    }

    vector<ll> pm(m + 1, 1);
    for (ll i = 1; i <= m; ++i) {
        pm[i] = pm[i - 1];
        for (auto& [r, p, q] : prob[i]) {
            pm[i] = mul(pm[i], mdiv((q - p), q));
        }
    }

    vector<ll> dp(m + 2);
    dp[1] = 1;
    for (ll i = 1; i <= m; ++i) {
        for (auto& [r, p, q] : prob[i]) {
            ll cmul = mdiv(pm[r], pm[i - 1]);
            cmul = mdiv(cmul, mdiv((q - p), q));
            cmul = mul(cmul, mdiv(p, q));
            dp[r + 1] = add(dp[r + 1], mul(dp[i], cmul));
        }
    }
    cout << dp[m + 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}