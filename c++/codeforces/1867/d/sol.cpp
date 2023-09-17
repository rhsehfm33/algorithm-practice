#include <bits/stdc++.h>

using namespace std;

bool go(int k, int cur, vector<int>& b, vector<bool>& vis, vector<bool>& cur_vis, vector<int>& path) {
    if (cur == b[cur]) {
        return false;
    }
    if ((path.size() >= k - 1 and path[(int)path.size() - (k - 1)] == b[cur]) or (vis[cur])) {
        vis[cur] = true;
        return true;
    }
    if (cur_vis[cur]) {
        return false;
    }
    path.push_back(cur);
    cur_vis[cur] = true;

    if (go(k, b[cur], b, vis, cur_vis, path)) {
        vis[cur] = true;
        path.pop_back();
        return true;
    }
    else {
        return false;
    }
}

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    if (k == 1) {
        for (int i = 1; i <= n; ++i) {
            if (b[i] != i) {
                cout << "No\n";
                return;
            }
        }

        cout << "Yes\n";
        return;
    }

    vector<int> path;
    vector<bool> vis(n + 1, false), cur_vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        if (go(k, i, b, vis, cur_vis, path) == false) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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