#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> lr(n);
    vector<array<int, 2>> sum(2 * n + 1);
    for (int i = 0; i < n; ++i) {
        auto& [l, r] = lr[i];
        cin >> l >> r;
        if (l == r) {
            sum[l][0] = 1;
            ++sum[r][1];
        }
    }

    for (int i = 2; i <= 2 * n; ++i) {
        sum[i][0] += sum[i - 1][0];
    }

    for (auto [l, r] : lr) {
        if (l == r) {
            cout << (sum[l][1] > 1 ? 0 : 1);
        } else {
            cout << (sum[r][0] - sum[l - 1][0] == r - l + 1 ? 0 : 1);
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