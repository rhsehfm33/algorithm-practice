#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, a, b;
    cin >> n >> a >> b;
    if ((a == b and a == n) or
        (n - a - b > 1)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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