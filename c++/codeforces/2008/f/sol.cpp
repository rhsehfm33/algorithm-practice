#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
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

void solve() {
    ll n, sum = 0, p = 0; cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
    }
    for (ll i = 0; i < n - 1; ++i) {
        sum -= a[i];
        p = (p + a[i] * (sum % MOD)) % MOD;
    }

    cout << (p * inv((n * (n - 1) / 2) % MOD)) % MOD << '\n';
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