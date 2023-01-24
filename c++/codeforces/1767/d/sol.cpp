#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if (ch == '0') {
            ++c0;
        }
        else {
            ++c1;
        }
    }

    int lb = pow(2, c1);
    int ub = pow(2, n) - (pow(2, c0) - 1);
    for (int i = lb; i <= ub; ++i) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}