#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            ++c0;
        } else {
            ++c1;
        }
    }

    int i = 0;
    for (; i < s.size(); ++i) {
        if (s[i] == '0' and c1) {
            --c1;
        } else if (s[i] == '1' and c0) {
            --c0;
        } else {
            break;
        }
    }
    cout << s.size() - i << '\n';
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