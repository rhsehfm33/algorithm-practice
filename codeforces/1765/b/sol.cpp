#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 1; i < s.size(); i += 3) {
        if (i + 1 >= s.size() or s[i] != s[i + 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}