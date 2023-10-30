#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    map<int, int> m;
    while (n--) {
        int ai;
        cin >> ai;
        ++m[ai];
    }

    if (m.size() == 1) {
        cout << "YES\n";
    } else if (m.size() == 2 and abs(m.begin()->second - m.rbegin()->second) <= 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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