#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    vector<int> v(3);
    cin >> v[0];
    v[1] = (1 << (int)log2(v[0])) - 1;
    v[2] = v[0] ^ v[1];
    sort(v.begin(), v.end());
    cout << (v[2] < v[0] + v[1] ? v[0] : -1) << '\n';
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