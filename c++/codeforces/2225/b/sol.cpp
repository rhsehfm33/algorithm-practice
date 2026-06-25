#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0, j = 0; i < s.size(); i = j) {
        while (j < s.size() and s[i] == s[j]) {
            ++j;
        }
        cnt += (j - i - 1);
    }
    cout << (cnt <= 2 ? "YES\n" : "NO\n");
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