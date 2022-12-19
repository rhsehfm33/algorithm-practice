#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int x = 2, c0 = 0, c1 = 0, case0 = 1, case1 = 1; x <= n; ++x) {
        if (s[x - 2] == '0') {
            ++c0;
            case1 = 1 + c0 + c1;
            cout << case0 << ' ';
        }
        else {
            ++c1;
            case0 = 1 + c0 + c1;
            cout << case1 << ' ';
        }
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