#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    stack<int> l, u;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') {
            if (u.size()) {
                s[u.top()] = '!';
                u.pop();
            }
        } else if (s[i] == 'b') {
            if (l.size()) {
                s[l.top()] = '!';
                l.pop();
            }
        } else if (s[i] >= 'a') {
            l.push(i);
        } else {
            u.push(i);
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '!' and s[i] != 'B' and s[i] != 'b') {
            cout << s[i];
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