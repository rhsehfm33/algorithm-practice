#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> b2i;
    vector<vector<int>> b(n);
    for (int i = 0, idx = 0; i < n; ++i) {
        int k;
        cin >> k;
        b[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> b[i][j];
            b2i[b[i][j]] = 0;
        }
    }
    
    int temp = 0;
    for (auto& [bi, idx] : b2i) {
        idx = temp++;
    }

    int split = 0;
    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < b[i].size()) {
            int prv_idx = b2i[b[i][j]] - 1;
            while (j < b[i].size() and prv_idx + 1 == b2i[b[i][j]]) {
                ++j;
                ++prv_idx;
            }
            if (j < b[i].size()) {
                ++split;
            }
        }
    }

    cout << split << ' ' << n + split - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}