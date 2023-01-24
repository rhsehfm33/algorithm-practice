#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<int> r2_max_left(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        r2_max_left[r] = max(r2_max_left[r], l);
    }

    long long ans = 0;
    for (int r = 1, max_left = 0; r <= n; ++r) {
        max_left = max(max_left, r2_max_left[r]);
        ans += (r - max_left);
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