#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

int _ti;

bool isLinked(string& a, string& b) {
    for (auto& ac : a) {
        for (auto& bc : b) {
            if (ac == bc) {
                return true;
            }
        }
    }
    return false;
}

int cal(int xi, int yi, int ti) {
    if (ti < xi) {
        return (xi - ti) * 2 + (yi - xi);
    } else if (ti > yi) {
        return (ti - yi) * 2 + (yi - xi);
    } else {
        return (yi - xi);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    map<string, vector<int>> m;
    vector<string> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        m[c[i]].push_back(i);
    }

    while (q--) {
        int xi, yi;
        cin >> xi >> yi;
        --xi, --yi;
        if (xi > yi) {
            swap(xi, yi);
        }
        if (isLinked(c[xi], c[yi])) {
            cout << abs(xi - yi) << '\n';
            continue;
        }

        int ans = MAX;
        for (auto& xc : c[xi]) {
            for (auto& yc : c[yi]) {
                string cc = string(1, xc) + string(1, yc);
                sort(cc.begin(), cc.end());
                auto it = lower_bound(m[cc].begin(), m[cc].end(), xi);
                if (it != m[cc].end()) {
                    ans = min(ans, cal(xi, yi, *it));
                }
                if (it != m[cc].begin()) {
                    ans = min(ans, cal(xi, yi, *prev(it)));
                }
            }
        }
        if (ans == MAX) {
            ans = -1;
        }
        cout << ans << '\n';
    }
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