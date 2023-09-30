#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> d2s(501, MAX);
    for (int i = 0; i < n; ++i) {
        int d, s;
        cin >> d >> s;
        d2s[d] = min(d2s[d], s);
    }

    for (int i = 1, mn = 1e9; i <= 500; ++i) {
        mn = min(mn, i + (d2s[i] - 1) / 2);
        if (i == mn) {
            cout << i << '\n';
            return;
        }
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