#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string p, s;
    cin >> p >> s;
    if (s[0] != p[0]) {
        cout << "NO\n";
        return;
    }

    int pi = 0, si = 0;
    while (pi < p.size() and si < s.size()) {
        int ppi = pi;
        while (pi < p.size() and p[ppi] == p[pi]) {
            ++pi;
        }
        int ssi = si;
        while (si < s.size() and s[ssi] == s[si]) {
            ++si;
        }
        int sl = si - ssi;
        int pl = pi - ppi;
        if (sl > pl * 2 or sl < pl) {
            cout << "NO\n";
            return;
        }
    }
    cout << (pi == p.size() and si == s.size() ? "YES\n" : "NO\n");
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