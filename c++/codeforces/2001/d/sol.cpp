#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    vector<int> ans;
    set<int> used;
    map<int, int> li, m;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        li[a[i]] = i;
    }

    for (int l = 0, r = 0; r < n; ++r) {
        if (used.count(a[r])) {
            continue;
        }
        ++m[a[r]];
        if (r != li[a[r]]) {
            continue;
        }

        while (!used.count(a[r])) {
            if (used.count(a[l])) {
                ++l;
                continue;
            }

            --m[a[l]];
            if ((used.size() % 2 and a[l] == m.begin()->first) or
            (used.size() % 2 == 0 and a[l] == m.rbegin()->first)) {
                m.erase(a[l]);
                used.insert(a[l]);
                ans.push_back(a[l]);
            } else if (m[a[l]] == 0) {
                m.erase(a[l]);
            }
            ++l;
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