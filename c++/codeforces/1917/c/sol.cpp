#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n), v(k);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& vi : v) {
        cin >> vi;
    }

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == i + 1) {
            ++cnt;
        }
    }
    ans += cnt + (d - 1) / 2;

    for (int i = 0; i <= 2 * n and i + 2 <= d; ++i) {
        for (int j = 0; j < v[i % k]; ++j) {
            ++a[j];
            if (a[j] == j + 1) {
                ++cnt;
            } else if (a[j] == j + 2) {
                --cnt;
            }
        }
        ans = max(ans, cnt + (d - 2 - i) / 2);
    }

    cout << ans << '\n';
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