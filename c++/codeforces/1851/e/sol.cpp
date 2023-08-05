#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<ll> cs(n);
    for (auto& ci : cs) {
        cin >> ci;
    }
    for (int i = 0; i < k; ++i) {
        int pi;
        cin >> pi;
        cs[--pi] = 0;
    }

    vector<ll> ind(n);
    vector<vector<ll>> u2v(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        ind[i] = m;
        for (int j = 0; j < m; ++j) {
            int ej;
            cin >> ej;
            u2v[--ej].push_back(i);
        }
    }

    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({cs[i], i});
    }

    vector<ll> indCost(n);
    while (pq.size()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost > cs[u]) {
            continue;
        }

        for (int v : u2v[u]) {
            indCost[v] += cs[u];
            if (--ind[v] == 0 and indCost[v] < cs[v]) {
                cs[v] = indCost[v];
                pq.push({cs[v], v});
            }
        }
    }

    for (auto ci : cs) {
        cout << ci << ' ';
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