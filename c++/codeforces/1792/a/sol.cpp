#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& hi : h) {
        cin >> hi;
    }

    int c1 = 0;
    for (auto hi : h) {
        c1 += (hi == 1);
    }

    cout << n - c1 / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}