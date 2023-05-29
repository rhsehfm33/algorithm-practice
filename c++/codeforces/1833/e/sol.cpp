#include <bits/stdc++.h>

using namespace std;

struct Dsu {
    vector<int> par;

    Dsu(int n) {
        par.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return false;
        }

        if (x > y) {
            swap(x, y);
        }
        par[y] = x;

        return true;
    }
};

void solve(int _ti) {
    int n;
    cin >> n;
    Dsu dsu(n);
    set<array<int, 2>> s;

    int closed = 0;
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        if (dsu.merge(i, ai) == false and s.count({i, ai}) == 0) {
            ++closed;
        }
        s.insert({i, ai});
        s.insert({ai, i});
    }

    set<int> total;
    for (int i = 1; i <= n; ++i) {
        total.insert(dsu.find(i));
    }

    if (total.size() == closed) {
        cout << closed << ' ' << closed << '\n';
    }
    else {
        cout << closed + 1 << ' ' << total.size() << '\n';
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