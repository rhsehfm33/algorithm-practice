#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int _ti;

void solve() {
    vector<int> c(1e5 + 1, 1);
    for (int i = 1; i <= 1e5; ++i) {
        c[i] = (c[i - 1] * 2) % MOD;
    }

    int t;
    cin >> t;
    vector<int> n(t), k(t);
    for (int& ni : n) {
        cin >> ni;
    }
    for (int& ki : k) {
        cin >> ki;
        cout << c[ki] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}