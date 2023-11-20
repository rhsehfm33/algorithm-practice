#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int b = k;
    for (char ch : s) {
        b -= ch == 'B';
    }
    if (b == 0) {
        cout << 0 << '\n';
        return;
    }

    char ch = b > 0 ? 'B' : 'A';
    b = abs(b);
    for (int i = 0; i < n; ++i) {
        b -= s[i] != ch;
        if (b == 0) {
            cout << 1 << '\n' << i + 1 << ' ' << ch << '\n';
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