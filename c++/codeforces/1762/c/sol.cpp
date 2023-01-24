#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll mod_add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

ll mod_mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

void solve(int _ti) {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 1;
    for (ll i = 1, pow = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            pow = mod_mul(pow, 2);
            ans = mod_add(ans, pow);
        }
        else {
            pow = 1;
            ans = mod_add(ans, pow);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}