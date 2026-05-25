#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string s;
    cin >> s;

    int suf = 0;
    for (char c : s) {
        if (c == '1' or c == '3') {
            ++suf;
        }
    }

    int pref2 = 0;
    int best = suf;
    for (char c : s) {
        if (c == '4') {
            continue;
        }
        if (c == '2') {
            ++pref2;
        } else {
            --suf;
        }
        best = max(best, pref2 + suf);
    }

    cout << (int)s.size() - best << '\n';
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