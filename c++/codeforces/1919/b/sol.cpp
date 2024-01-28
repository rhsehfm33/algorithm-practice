#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int p = 0, m = 0, n;
    cin >> n;
    while (n--) {
        char ch;
        cin >> ch;
        if (ch == '+') {
            ++p;
        } else {
            ++m;
        }
    }

    cout << abs(p - m) << '\n';
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