#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = 0;
    vector<bool> presum(1 << 8, false);
    presum[0] = true;
    for (int i = 0, sum = 0; i < n; ++i) {
        sum ^= a[i];
        for (int j = 0; j < (1 << 8); ++j) {
            if (presum[j]) {
                ans = max(ans, sum ^ j);
            }
        }
        presum[sum] = true;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}