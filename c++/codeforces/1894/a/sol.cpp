#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            ++a;
        } else {
            ++b;
        }
    }

    if (a == b) {
        cout << "?\n";
    } else if (s.back() == 'A') {
        cout << "A\n";
    } else {
        cout << "B\n";
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