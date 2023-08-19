#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    vector<int> ans = {1};
    vector<bool> vis(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }

        for (int j = i; j <= n; j *= 2) {
            vis[j] = true;
            ans.push_back(j);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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