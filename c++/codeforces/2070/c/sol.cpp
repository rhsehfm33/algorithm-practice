#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    int l = 0, h = 1e9;
    while (l <= h) {
        int m = (l + h) / 2;
        int ck = k;
        for (int i = 0, c = 0; i < n; ++i) {
            if (s[i] == 'R' and p[i] > m) {
                c = 0;
            }
            if (s[i] == 'B' and p[i] > m and !c) {
                c = 1;
                --ck;
            }
        }
        if (ck >= 0) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << l << '\n';
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