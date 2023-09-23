#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;

    int u = -1, d = n, l = -1, r = n;
    vector<vector<int>> k2i(k + 1);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        k2i[ai].push_back(i);
    }

    vector<bool> vc(n, false), vr(n, false);
    for (int i = 1; i <= k; ++i) {
        if (k2i[i].empty()) {
            cout << 0 << ' ';
            continue;
        }
        
        cout << (r - l - 1) + (d - u - 1) << ' ';
        for (int j = 0; j < k2i[i].size(); ++j) {
            int cur = k2i[i][j];
            vc[cur] = true;
            vr[cur] = true;
        }
        while (l + 1 < n and vc[l + 1]) {
            ++l;
        }
        while (r - 1 >= 0 and vc[r - 1]) {
            --r;
        }
        while (u + 1 < n and vr[u + 1]) {
            ++u;
        }
        while (d - 1 >= 0 and vr[d - 1]) {
            --d;
        }
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