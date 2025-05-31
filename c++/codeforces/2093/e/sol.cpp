#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int l = 0, h = 3e5;
    while (l <= h) {
        vector<bool> vis(n);
        int m = (l + h) / 2, ck = 0;
        for (int i = 0, j = 0, mx = 0; i < n; ++i) {
            if (a[i] < n) {
                vis[a[i]] = true;
            }
            while (mx < n and vis[mx]) {
                ++mx;
            }
            if (mx >= m) {
                mx = 0;
                ++ck;
                while (j <= i) {
                    if (a[j] < n) {
                        vis[a[j]] = false;
                    }
                    ++j;
                }
            }
        }
        if (ck >= k) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    cout << h << '\n';
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
