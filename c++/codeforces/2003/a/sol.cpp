#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    cout << (s[0] != s[n - 1] ?  "Yes" : "No") << '\n';
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