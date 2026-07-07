#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (s.size() and s.back() == '1') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    while (s.size() and s.back() == '0') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());

    for (int i = 0, j = 0; i < s.size(); i = j) {
        while (j < s.size() and s[i] == s[j]) {
            ++j;
        }
        if ((j - i) % 2) {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
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