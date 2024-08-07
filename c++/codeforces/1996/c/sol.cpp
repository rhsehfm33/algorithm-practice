#include <bits/stdc++.h>

using namespace std;

int _ti;

void init(vector<vector<int>>& c) {
    for (int i = 1; i < c.size(); ++i) {
        char ch;
        cin >> ch;
        c[i] = c[i - 1];
        ++c[i][ch - 'a'];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> ca(n + 1, vector<int>(26)), cb(n + 1, vector<int>(26));
    init(ca);
    init(cb);

    while (q--) {
        int l, r, sum = 0;
        cin >> l >> r;
        for (int i = 0; i < 26; ++i) {
            sum += abs((ca[r][i] - ca[l - 1][i]) - (cb[r][i] - cb[l - 1][i]));
        }
        cout << sum / 2 << '\n';
    }
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