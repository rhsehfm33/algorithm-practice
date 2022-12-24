#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, K, D;
ll dp[101][101][101];
ll a[101];

void solve() {
    cin >> N >> K >> D;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    ll ans = -1;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int r = 0; r < D; ++r) {
                if (dp[i][j][r] == -1) {
                    continue;
                }
                dp[i + 1][j][r] = max(dp[i + 1][j][r], dp[i][j][r]);
                dp[i + 1][j + 1][(r + a[i]) % D] = max(dp[i + 1][j + 1][(r + a[i]) % D], dp[i][j][r] + a[i]);
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        ans = max(ans, dp[i][K][0]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}