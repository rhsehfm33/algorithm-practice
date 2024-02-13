#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int a, b;
    cin >> a >> b;
    if ((a % 2 and b % 2) or ((a + b) % 2 and min(a, b) * 2 == max(a, b))) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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