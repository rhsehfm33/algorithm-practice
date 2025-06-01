#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1), pi2i(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pi2i[p[i]] = i;
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        if (pi2i[k] < l or pi2i[k] > r) {
            cout << "-1 ";
            continue;
        }

        int sm = 1, bg = n, sm2 = 1, bg2 = n, ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (p[m] == k) {
                break;
            }
            if (pi2i[k] > pi2i[p[m]]) {
                ++sm;
                l = m + 1;
                ans += k < p[m];
            } else {
                --bg;
                r = m - 1;
                ans += k > p[m];
            }
            if (p[m] < k) {
                ++sm2;
            } else {
                --bg2;
            }
        }
        if (sm > k or bg < k) {
            cout << "-1 ";
        } else {
            cout << ans + abs(bg - bg2) << ' ';
        }
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