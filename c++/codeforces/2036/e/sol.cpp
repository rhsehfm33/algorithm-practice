#include <bits/stdc++.h>

using namespace std;

int getBound(vector<int>& rs, int c, char o) {
    int l = 0, h = rs.size();
    while (l <= h) {
        int m = (l + h) / 2;
        if (o == '<') {
            if (rs[m] >= c) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if (rs[m] <= c) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
    }
    return o == '<' ? h : l;
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> rs(k, vector<int>(n));
    for (int c = 0; c < n; ++c) {
        for (int r = 0; r < k; ++r) {
            cin >> rs[r][c];
            if (c) {
                rs[r][c] |= rs[r][c - 1];
            }
        }
    }

    while (q--) {
        int lb = 0, hb = n - 1;

        int m;
        cin >> m;
        while (m--) {
            int r;
            char o;
            int c;
            cin >> r >> o >> c;
            --r;
            if (o == '>') {
                lb = max(lb, getBound(rs[r], c, o));
            } else {
                hb = min(hb, getBound(rs[r], c, o));
            }
        }
        
        if (lb <= hb) {
            cout << lb + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}