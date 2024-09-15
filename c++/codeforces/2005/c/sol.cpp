#include <bits/stdc++.h>
 
using namespace std;
 
const string narek = "narek";
const int INIT = -1e9;
 
int _ti;
 
void solve() {
    int n, m;
    cin >> n >> m;
    string s = "";
    for (int i = 0; i < n; ++i) {
        string cs; cin >> cs;
        s += cs;
    }
 
    vector<vector<int>> dp(n * m + 1, vector<int>(5, INIT));
    dp[0][0] = 0;
    for (int i = 0; i < n * m; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (dp[i][j] == INIT) {
                continue;
            }
 
            if (i % m == 0) {
                dp[i + m][j] = max(dp[i + m][j], dp[i][j]);
            }
            
            if (s[i] == narek[j]) {
                dp[i + 1][(j + 1) % 5] = max(dp[i + 1][(j + 1) % 5], dp[i][j] + (j % 5 == 4 ? 5 : 0));
            }
            
            if (narek.find(s[i]) != string::npos) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
            } else {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }
    }
 
    cout << max(0, dp[n * m][0]) << '\n';
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