#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int a1 = 0, b1 = 0, dc = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++dc;
        }
        a1 += a[i] - '0';
        b1 += b[i] - '0';
    }

    cout << abs(a1 - b1) + (dc - abs(a1 - b1)) / 2 << '\n';
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