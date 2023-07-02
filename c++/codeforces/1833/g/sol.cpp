#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par;
    vector<int> count;

    DSU(int n) {
        for (int i = 0; i <= n; ++i) {
            par.push_back(i);
            count.push_back(1);
        }
    }

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    int merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return -1;
        }
        if (count[x] >= 3 or count[y] >= 3) {
            return -2;
        }

        if (x > y) {
            swap(x, y);
        }
        par[y] = x;
        count[x] += count[y];

        return count[x];
    }
};

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> fromTo(n + 1);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        fromTo[u].push_back({i, v});
        fromTo[v].push_back({i, u});
    }

    if (n % 3 != 0) {
        cout << -1 << '\n';
        return;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (fromTo[i].size() == 1) {
            q.push(i);
        }
    }

    set<int> ans;
    vector<int> ind(n + 1);
    DSU dsu(n + 1);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto [i, v] : fromTo[u]) {
            int mergeResult = dsu.merge(u, v);
            if (mergeResult == -1) {
                continue;
            }

            if (mergeResult == -2 and ans.count(i) == 0) {
                ans.insert(i);
            }
            if (++ind[v] == (int)fromTo[v].size() - 1) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dsu.count[dsu.find(i)] != 3) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << ans.size() << '\n';
    for (int ai : ans) {
        cout << ai << ' ';
    }
    cout << '\n';
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