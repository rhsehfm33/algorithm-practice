#include <bits/stdc++.h>
 
using namespace std;
 
int _ti;
 
 
int get_nlb(vector<vector<int>>& bs, int h, int l, int bi, int bc) {
    while (l <= h) {
        int m = (l + h) / 2;
        if (bs[m][bi] < bc) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return l;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> w(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    reverse(w.begin(), w.end());
 
    vector<vector<int>> bs(n + 1, vector<int>(30));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 30; ++j) {
            bs[i][j] = bs[i - 1][j] + ((w[i] >> j) & 1);
        }
    }
 
    while (q--) {
        int x;
        cin >> x;
        int l = 0, h = n;
        for (int i = 29; i >= 0 and l < h; --i) {
            int bit = (x >> i) & 1;
            if ((bit + bs[l][i]) % 2) {
                int nl = get_nlb(bs, h, l, i, bs[l][i] + 1);
                int nh = get_nlb(bs, h, l, i, bs[l][i] + 2);
                l = nl <= h ? nl - 1 : h;
                h = nh <= h ? nh - 1 : h;
            } else {
                int nh = get_nlb(bs, h, l, i, bs[l][i] + 1);
                h = nh <= h ? nh - 1 : h;
            }
        }
        cout << h << ' ';
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