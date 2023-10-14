#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n % 3 and n >= 7) {
        cout << "YES\n1 2 " << n - 3 << '\n';
    }
    else if (n >= 10) {
        cout << "YES\n1 4 " << n - 5 << '\n';
    }
    else {
        cout << "NO\n";
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