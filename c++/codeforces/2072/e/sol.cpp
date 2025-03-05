#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int k;
    cin >> k;
    int s = 0;
    vector<array<int, 2>> ans = {{s, s}};
    while (k) {
        int a = 1;
        while (k - a >= 0) {
            k -= a;
            ans.push_back({s, s + a});
            ++a;
        }
        if (k) {
            s += 1000;
            ans.push_back({s, s});
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
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