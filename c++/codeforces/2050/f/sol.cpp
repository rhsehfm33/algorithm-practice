#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    vector<vector<int>> sp(n, vector<int>((int)log2(n) + 1));
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; i + (1 << (j + 1)) <= n; ++j) {
            sp[i][j + 1] = abs(a[i] - a[i + (1 << j)]);
            sp[i][j + 1] = gcd(sp[i][j + 1], sp[i][j]);
            sp[i][j + 1] = gcd(sp[i][j + 1], sp[i + (1 << j)][j]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        int len = r - l + 1;
        int ans = 0;
        for (int i = 0, cl = l; (1 << i) <= len; ++i) {
            if (len & (1 << i)) {
                ans = gcd(ans, abs(a[l] - a[cl]));
                ans = gcd(ans, sp[cl][i]);
                cl = cl + (1 << i);
            }
        }
        cout << ans << ' ';
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