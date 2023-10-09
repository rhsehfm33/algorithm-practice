#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "a\n";
        return;
    }

    int d = 2;
    while (true) {
        if (n % d or n == d) {
            break;
        }
        ++d;
    }

    for (int i = 0; i < n; ++i) {
        cout << (char)('a' + i % d);
    }
    cout << '\n';
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