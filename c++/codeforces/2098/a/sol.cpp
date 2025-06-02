#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (s[j] >= '9' - i and s[j] < s[i]) {
                swap(s[j], s[i]);
            }
        }
    }
    cout << s << '\n';
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