#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    string s;
    cin >> n >> k >> s >> q;
    vector<int> dp(n + 1);
    vector<vector<int>> near(n + 1, vector<int>(k, n));

    vector<int> cnear(k, n);
    for (int i = n - 1; i >= 0; --i) {
        cnear[s[i] - 'a'] = i;
        near[i] = cnear;
        dp[i] = 1e9;
        for (int j = 0; j < k; ++j) {
            dp[i] = min(dp[i], dp[near[i + 1][j]] + 1);
        }
    }

    while (q--) {
        string t;
        cin >> t;
        int idx = -1;
        for (char ti : t) {
            if (idx == n) {
                break;
            }
            idx = min(n, near[idx + 1][ti - 'a']);
        }
        cout << dp[idx] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}