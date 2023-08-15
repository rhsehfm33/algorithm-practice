#include <bits/stdc++.h>

using namespace std;

int getMax(vector<int> indices, int n) {
    indices.insert(indices.begin(), -1);
    indices.push_back(n);
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i + 1 < indices.size(); ++i) {
        int len = indices[i + 1] - indices[i] - 1;
        if (len > mx1) {
            mx2 = mx1;
            mx1 = len;
        }
        else if (len > mx2) {
            mx2 = len;
        }
    }

    return max(mx1 / 2, mx2);
}

void solve(int _ti) {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> c2i(n + 1);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c2i[c[i]].push_back(i);
    }

    int mn = 1e9;
    for (int i = 1; i <= k; ++i) {
        if (c2i[i].size()) {
            mn = min(mn, getMax(c2i[i], n));
        }
    }
    cout << mn << '\n';
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