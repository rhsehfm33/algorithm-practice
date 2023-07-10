#include <bits/stdc++.h>

using namespace std;

int getLeafSum(vector<int>& treeLeafSum, vector<vector<int>>& u2v, int u, int p) {
    for (int v : u2v[u]) {
        if (v != p) {
            treeLeafSum[u] += getLeafSum(treeLeafSum, u2v, v, u);
        }
    }

    if (treeLeafSum[u] == 0) {
        treeLeafSum[u] = 1;
    }

    return treeLeafSum[u];
}

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int ui, vi;
        cin >> ui >> vi;
        u2v[ui].push_back(vi);
        u2v[vi].push_back(ui);
    }

    vector<int> treeLeafSum(n + 1);
    getLeafSum(treeLeafSum, u2v, 1, 0);

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (long long)treeLeafSum[x] * treeLeafSum[y] << '\n';
    }
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