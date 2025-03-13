#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 2, pi; i <= n; ++i) {
        cin >> pi;
        u2v[pi].push_back(i);
    }

    queue<int> q;
    q.push(1);
    ll sum = 1, ans = 1;
    vector<ll> dp(n + 1);
    while (q.size()) {
        ll nsum = 0;
        ll ql = q.size();
        while (ql--) {
            int u = q.front(); q.pop();
            for (int v : u2v[u]) {
                dp[v] = (dp[v] + sum - dp[u] + MOD) % MOD;
                nsum = (nsum + dp[v]) % MOD;
                q.push(v);
            }
        }
        sum = nsum;
        ans = (ans + sum) % MOD;
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