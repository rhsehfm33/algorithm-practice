#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    int c1 = 0;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        c1 += (ch == '1');
    }
    if (n < 2 * k or c1 <= k) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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