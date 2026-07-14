#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;
const ll MOD = 1e9 + 7;
const ll MAX = 2e5 + 5;
ll p2[MAX];

ll add(ll n1, ll n2) {
    return (n1 + n2) % MOD;
}

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

void preset() {
    p2[0] = 1;
    for (ll i = 1; i < MAX; ++i) {
        p2[i] = mul(p2[i - 1], 2);
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<array<ll, 2>> c;
    for (ll i = 0, ai; i < n; ++i) {
        cin >> ai;
        if (c.size() and c.back()[0] == ai) {
            ++c.back()[1];
        } else {
            c.push_back({ai, 1});
        }
    }

    vector<array<ll, 4>> dp(c.size() + 1);
    dp[0][0] = 1;
    for (ll i = 0; i < c.size(); ++i) {
        ll p = p2[c[i][1] - 1];

        // odd appear 0
        dp[i + 1][0] = add(dp[i + 1][0], mul(dp[i][0], p));
        if (c[i][0] == -1) {
            dp[i + 1][1] = add(dp[i + 1][1], mul(dp[i][0], p));
        }

        // odd appear 1
        dp[i + 1][1] = add(dp[i + 1][1], mul(dp[i][1], p));
        if (i + 1 < c.size() and c[i][0] + 1 == c[i + 1][0]) {
            dp[i + 1][2] = add(dp[i + 1][2], mul(dp[i][1], p));
        }

        // odd appear 2
        dp[i + 1][3] = add(dp[i + 1][3], mul(dp[i][2], p));

        // odd appear 3
        dp[i + 1][3] = add(dp[i + 1][3], mul(dp[i][3], p));
    }
    cout << add(dp.back()[0], dp.back()[3]) << '\n';
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