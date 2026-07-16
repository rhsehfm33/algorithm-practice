#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = s.front() + s;
    vector<int> ps(n + 1);
    for (int i = 1; i <= n; ++i) {
        ps[i] = (s[i] == s[i - 1]) + ps[i - 1];
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        if (k >= (ps[r] - ps[l] + 1) / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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