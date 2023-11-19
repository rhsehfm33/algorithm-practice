#include <bits/stdc++.h>

using namespace std;

array<int, 3> push(int c, vector<int>& f, vector<int>& t) {
    array<int, 3> result = {f[f.size() - c], f[f.size() - c - 1], t.back()};
    t.insert(t.end(), f.end() - c, f.end());
    f.erase(f.end() - c, f.end());
    return result;
}

void solve(int _ti) {
    int n, q;
    cin >> n >> q;
    vector<int> up, right = {n - 1}, qs;
    for (int i = n - 1; i >= 1; --i) {
        up.push_back(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << i + 1 << ' ' << i + 2 << '\n';
    }
    while (q--) {
        int di;
        cin >> di;
        if (di == right.size() or di == up.size()) {
            cout << "-1 -1 -1\n";
            continue;
        }

        auto [u, v1, v2] = right.size() < di ? push(di - right.size(), up, right) : push(right.size() - di, right, up);
        cout << u << ' ' << v1 << ' ' << v2 << '\n';
    }
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