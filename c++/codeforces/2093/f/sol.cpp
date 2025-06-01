#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int mx = 0;
    set<int> s;
    vector<int> mcnt(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            string bij;
            cin >> bij;
            if (a[j] == bij) {
                mx = max(mx, ++mcnt[i]);
                s.insert(j);
            }
        }
    }
    if (s.size() < n) {
        cout << "-1\n";
        return;
    }
    cout << (n - mx) * 2 + n << '\n';
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