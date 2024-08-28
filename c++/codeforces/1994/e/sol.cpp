#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int k; cin >> k;
    vector<int> t(k);
    for (int i = 0; i < k; ++i) {
        cin >> t[i];
        for (int j = 0; j < t[i] - 1; ++j) {
            int pi; cin >> pi;
        }
    }

    int ans = 0;
    sort(t.rbegin(), t.rend());
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 19; j >= 0; --j) {
            while (((t[i] >> j) & 1) and ((ans >> j) & 1)) {
                --t[i];
                ans |= 1;
            }
        }
        ans |= t[i];
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