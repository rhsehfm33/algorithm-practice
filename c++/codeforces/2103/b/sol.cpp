#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, dif = 0;
    cin >> n;
    string s;
    cin >> s;
    s = "0" + s;
    for (int i = 1; i <= n; ++i) {
        dif += s[i - 1] != s[i];
    }
    if (dif <= 1) {
        cout << n + dif << '\n';
    } else if (dif == 2) {
        cout << n + 1 << '\n';
    } else {
        cout << n + dif - 2 << '\n';
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