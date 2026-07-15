#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const short MAX = 5000;
const short INIT = -6000;
short dp[MAX + 5][MAX + 5];

int _ti;

void preset(string& s, vi& mod, vvi& c) {
    vi cc(10, -1);
    for (int i = s.size() - 1; i >= 0; --i) {
        c[i] = cc;
        for (int j = i, m = 0; j < s.size(); ++j) {
            m = (m + s[j] - '0') % 10;
            if (c[i][m] == -1) {
                c[i][m] = j + 1;
            }
            if (j == s.size() - 1) {
                mod[i] = m;
            }
        }
    }
}

short go(int ai, int bi, vi& am, vvi& ac, vi& bm, vvi& bc) {
    if (ai >= ac.size() or bi >= bc.size()) {
        return -1;
    }
    if (dp[ai][bi] != INIT) {
        return dp[ai][bi];
    }
    dp[ai][bi] = (am[ai] == bm[bi] ? 1 : -1);
    for (int d = 0; d < 10; ++d) {
        if (ac[ai][d] != -1 and bc[bi][d] != -1) {
            short cnt = 1 + go(ac[ai][d], bc[bi][d], am, ac, bm, bc);
            if (cnt) {
                dp[ai][bi] = max(dp[ai][bi], cnt);
            }
        }
    }
    return dp[ai][bi];
}

void solve() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        fill(dp[i], dp[i] + b.size(), INIT);
    }

    vi am(a.size()), bm(b.size());
    vvi ac(a.size()), bc(b.size());
    preset(a, am, ac);
    preset(b, bm, bc);
    cout << go(0, 0, am, ac, bm, bc) << '\n';
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