#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i] == '0' and a[i + 1] == '1' and b[i] == '0' and b[i + 1] == '1') {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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