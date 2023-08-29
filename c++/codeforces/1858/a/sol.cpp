#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c & 1) {
        if (b > a) {
            cout << "Second";
        }
        else {
            cout << "First";
        }
    }
    else {
        if (a > b) {
            cout << "First";
        }
        else {
            cout << "Second";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}