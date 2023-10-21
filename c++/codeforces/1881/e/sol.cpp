#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int go(vector<int>& a, vector<int>& dp, int i) {
    if (i == a.size()) {
        return 0;
    }
    if (i > a.size()) {
        return INF;
    }
    if (dp[i] != -1) {
        return dp[i];
    }

    int r1 = go(a, dp, i + a[i] + 1);
    int r2 = go(a, dp, i + 1) + 1;
    return dp[i] = min(r1, r2);
}

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> dp(n, -1);
    cout << go(a, dp, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}