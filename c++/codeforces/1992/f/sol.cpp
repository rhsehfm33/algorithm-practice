#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = 0;
    for (int i = 0; i < n;) {
        set<int> s{x};
        while (i < n and !s.count(a[i])) {
            vector<int> ns;
            for (auto si : s) {
                if (si % a[i] == 0 and !s.count(si / a[i])) {
                    ns.push_back(si / a[i]);
                }
            }
            s.insert(ns.begin(), ns.end());
            ++i;
        }
        ++ans;
    }

    cout << ans << '\n';
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