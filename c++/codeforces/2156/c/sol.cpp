#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 2);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        for (int j = 1; j * j <= ai; ++j) {
            int k = ai / j;
            int kr = ai % j;
            if (j >= 4) {
                ++cnt[j];
                --cnt[k + 1];
                break;
            }
            if (k >= 4 or kr == 0) {
                ++cnt[j];
                --cnt[j + 1];
            }
            if (kr == 0 and k != j) {
                ++cnt[k];
                --cnt[k + 1];
            }
        }
    }

    int ans = 1;
    for (int i = 1, c = 0; i <= n; ++i) {
        c += cnt[i];
        if (c >= n - k) {
            ans = i;
        }
    }
    cout << ans << '\n';
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