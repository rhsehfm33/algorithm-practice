#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    while (n--) {
        int ci;
        cin >> ci;
        ++v[ci - 1];
    }

    int c1 = 0, c = 0;
    for (auto vi : v) {
        if (vi == 1) {
            ++c1;
        } else if (vi) {
            ++c;
        }
    }

    cout << c1 + c1 % 2 + c << '\n';
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