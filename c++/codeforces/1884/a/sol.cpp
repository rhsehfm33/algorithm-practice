#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int x, k;
    cin >> x >> k;

    while (true) {
        int sum = 0;
        for (int cx = x; cx; cx /= 10) {
            sum += cx % 10;
        }
        if (sum % k == 0) {
            cout << x << '\n';
            return;
        }
        ++x;
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