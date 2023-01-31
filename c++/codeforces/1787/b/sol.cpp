#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;

    map<ll, ll> m;
    vector<array<ll, 2>> factors;
    ll cn = n;
    for (ll i = 2; i * i <= n; ++i) {
        while (cn % i == 0) {
            factors.push_back({m[i]++, i});
            cn /= i;
        }
    }
    if (cn > 1) {
        factors.push_back({m[cn]++, cn});
    }

    ll ans = 0;
    sort(factors.begin(), factors.end());
    for (int i = 0; i < factors.size(); ++i) {
        ll curMul = factors[i][1];
        while (i + 1 < factors.size() and factors[i][0] == factors[i + 1][0]) {
            curMul *= factors[++i][1];
        }
        ans += curMul;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}