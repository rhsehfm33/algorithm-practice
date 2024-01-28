#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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