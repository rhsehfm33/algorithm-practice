#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    string s = "";
    for (int i = 0; i < k; ++i) {
        s += string(1, 'a' + i);
    }
    for (int i = 0; i < n; ++i) {
        cout << s;
    }
    cout << '\n';
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