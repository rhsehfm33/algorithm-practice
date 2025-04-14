#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;
int _ti;

void madd(int& a, int b) {
    a = (a + b) % MOD;
}

void mmin(int& a, int b) {
    a = (a - b + MOD) % MOD;
}

void cal0(vector<vector<array<int, 2>>>& dp, vector<string>& g, int d, int ri) {
    int m = dp[0].size();
    for (int i = 0; i < 2; ++i) {
        for (int l = 0, r = 0, s = 0; r < m; ++r) {
            if (i == 0) {
                madd(s, dp[ri + 1][r][0]);
                madd(s, dp[ri + 1][r][1]);
            }

            while ((r - l) * (r - l) + 1 > d * d) {
                mmin(s, dp[ri + 1][l][0]);
                mmin(s, dp[ri + 1][l][1]);
                ++l;
            }
            if (g[ri][r] == 'X') {
                madd(dp[ri][r][0], s);
            }

            if (i != 0) {
                madd(s, dp[ri + 1][r][0]);
                madd(s, dp[ri + 1][r][1]);
            }
        }
        reverse(g[ri].begin(), g[ri].end());
        reverse(dp[ri].begin(), dp[ri].end());
        reverse(dp[ri + 1].begin(), dp[ri + 1].end());
    }
}

void cal1(vector<vector<array<int, 2>>>& dp, vector<string>& g, int d, int ri) {
    int m = dp[0].size();
    for (int i = 0; i < 2; ++i) {
        for (int l = 0, r = 0, s = 0; r < m; ++r) {
            while (r - l > d) {
                mmin(s, dp[ri][l][0]);
                ++l;
            }
            if (g[ri][r] == 'X') {
                madd(dp[ri][r][1], s);
            }
            madd(s, dp[ri][r][0]);
        }
        reverse(g[ri].begin(), g[ri].end());
        reverse(dp[ri].begin(), dp[ri].end());
    }
}

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> g(n);
    for (auto& gi : g) {
        cin >> gi;
    }

    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(m));
    for (int i = 0; i < m; ++i) {
        dp[n - 1][i][0] = g[n - 1][i] == 'X';
    }
    cal1(dp, g, d, n - 1);
    for (int ri = n - 2; ri >= 0; --ri) {
        cal0(dp, g, d, ri);
        cal1(dp, g, d, ri);
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        madd(ans, dp[0][i][0]);
        madd(ans, dp[0][i][1]);
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