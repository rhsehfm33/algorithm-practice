#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 10;
int _ti;

void solve() {
    int n, m, l, sum = 0, mn = 0;
    cin >> n >> m >> l;
    vector<int> A(l);
    for (auto& Ai : A) {
        cin >> Ai;
        sum += Ai;
        if (Ai % 2 and (!mn or Ai < mn)) {
            mn = Ai;
        }
    }

    vector<vector<int>> u2v(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    vector<array<int, 2>> dp(n + 1, {INF, INF});
    dp[1][0] = 0;
    queue<array<int, 2>> q;
    q.push({1, 0});
    while (q.size()) {
        auto [u, c] = q.front(); q.pop();
        for (int v : u2v[u]) {
            if (c + 1 < dp[v][(c + 1) % 2]) {
                dp[v][(c + 1) % 2] = c + 1;
                q.push({v, c + 1});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << (sum >= dp[i][sum % 2] or sum - mn >= dp[i][(sum - mn) % 2]);
    }
    cout << '\n';
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