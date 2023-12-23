#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    string t;
    for (char i = 'a'; i <= 'h'; ++i) {
        if (s[0] != i) {
            t = s;
            t[0] = i;
            cout << t << '\n';
        }
    }
    for (char i = '1'; i <= '8'; ++i) {
        if (s[1] != i) {
            t = s;
            t[1] = i;
            cout << t << '\n';
        }
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