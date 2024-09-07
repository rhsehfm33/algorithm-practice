#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi; --pi;
    }
    string s; cin >> s;

    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (ans[i] != -1) {
            continue;
        }

        int j = i, bc = 0;
        vector<int> v;
        do {
            bc += (s[j] == '0');
            v.push_back(j);
            j = p[j];
        } while (i != j);

        for (int vi : v) {
            ans[vi] = bc;
        }
    }

    for (int i = 0; i < n; ++i) {
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