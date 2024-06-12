#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int _ti;
vector<ll> p2;

ll add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

void preset() {
    for (ll i = 0, s = 1; i <= 3e5; ++i, s = mul(s, 2)) {
        p2.push_back(s);
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll mn = 0, ans = p2[n];
    for (ll i = 0, s = 0, m = 1; i < n; ++i) {
        s += a[i];
        if (s >= 0) {
            m = mul(m, 2);
        }

        if (s <= mn and s != 0) {
            if (s < mn) {
                mn = s;
                ans = 0;
            }
            ans = add(ans, mul(m, p2[n - i - 1]));
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}