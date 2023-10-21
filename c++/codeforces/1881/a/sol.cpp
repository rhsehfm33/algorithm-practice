#include <bits/stdc++.h>

using namespace std;

bool check(string b, string s) {
    for (int i = 0; i + s.size() <= b.size(); ++i) {
        if (b.substr(i, s.size()) == s) {
            return true;
        }
    }
    return false;
}

void solve(int _ti) {
    int n, m;
    string x, s;
    cin >> n >> m >> x >> s;

    int cnt = 0;
    while (x.size() < s.size()) {
        x += x;
        ++cnt;
    }

    if (check(x, s)) {
        cout << cnt << '\n';
    } else if (check(x + x, s)) {
        cout << cnt + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
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