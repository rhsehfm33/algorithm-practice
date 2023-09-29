#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<int>> e2i(51);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int e;
            cin >> e;
            e2i[e].push_back(i);
        }
    }

    int ans = 0;
    for (int e = 1; e <= 50; ++e) {
        if (e2i[e].empty()) {
            continue;
        }

        vector<bool> vis(n + 1);
        for (int i = 0; i < e2i[e].size(); ++i) {
            vis[e2i[e][i]] = true;
        }

        int sum = 0;
        for (auto& idxs : e2i) {
            bool diff = false;
            for (auto& idx : idxs) {
                if (vis[idx] == false) {
                    diff = true;
                    break;
                }
            }
            if (diff and idxs.size()) {
                ++sum;
            }
        }
        ans = max(ans, sum);
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