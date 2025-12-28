#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;

int _ti;

void solve() {
    ui n, k;
    cin >> n >> k;
    vector<ui> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<ui> b;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        for (ui ni = a[i] + a[i], li = i + 1; ni <= k; ni += a[i]) {
            auto it = lower_bound(a.begin() + li, a.end(), ni);
            if (it == a.end() or *it != ni) {
                cout << "-1\n";
                return;
            }
            li = it - a.begin();
            vis[li] = true;
        }
        b.push_back(a[i]);
    }

    cout << b.size() << '\n';
    for (auto bi : b) {
        cout << bi << ' ';
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