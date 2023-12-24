#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    map<char, int> m;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        ++m[ch];
    }

    int ans = 0;
    for (auto& [ch, cnt] : m) {
        if (cnt > ch - 'A') {
            ++ans;
        }
    }
    cout << ans << '\n';
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