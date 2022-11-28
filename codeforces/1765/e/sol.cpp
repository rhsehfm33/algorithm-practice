#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b) {
        cout << "1\n";
    }
    else {
        cout << n / a + (n % a ? 1 : 0) << '\n';
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