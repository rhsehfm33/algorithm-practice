#include <bits/stdc++.h>

using namespace std;

string STR_PI = "31415926535897932384626433832795028841971";

void solve(int _ti) {
    string n;
    cin >> n;
    for (int i = 0; i < n.size(); ++i) {
        if (n[i] != STR_PI[i]) {
            cout << i << '\n';
            return;
        }
    }

    cout << n.size() << '\n';
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