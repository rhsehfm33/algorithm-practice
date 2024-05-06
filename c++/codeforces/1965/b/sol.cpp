#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    vector<int> ans;

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i <<= 1) {
        if (k >= i and k <= (i << 1) - 1) {
            ans.push_back(k - i);
            ans.push_back(k + 1);
            ans.push_back((i << 1) | i);
        } else {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (auto& ansi : ans) {
        cout << ansi << ' ';
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