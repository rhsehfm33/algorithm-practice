#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    for (int i = 0; i < n; ++i) {
        int qi = (p[i] + 1) % n;
        qi = qi == 0 ? n : qi;
        cout << qi << ' ';
    }
    cout << '\n';
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