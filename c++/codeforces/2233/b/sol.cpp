#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n - n % 2; i += 2) {
        ans.insert(ans.end(), {i, i + 1, i + 1, i, i + 1, i, i, i + 1});
    }
    if (n % 2) {
        ans.insert(prev(ans.end()), n);
        ans.insert(ans.begin(), n);
        ans.insert(ans.end(), {n, n});
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
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