#include <bits/stdc++.h>
using namespace std;

int _ti;

struct uf {
    vector<int> p;
    uf(int n) {
        for (int i = 0; i <= n; ++i) {
            p.push_back(i);
        }
    }

    int find(int x) {
        return x == p[x] ? x : x = find(p[x]);
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
        p[y] = x;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> ab(n);
    for (auto& [a, b] : ab) {
        cin >> a >> b;
    }

    vector<int> ans;
    uf uf1(2 * n);
    for (int i = 0; i < n; ++i) {
        auto& [a, b] = ab[i];
        if (uf1.merge(a, b)) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}