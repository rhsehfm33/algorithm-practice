#include <bits/stdc++.h>

using namespace std;

bool isC(char c) {
    return c == 'b' or c == 'c' or c == 'd';
}

bool isV(char c) {
    return c == 'a' or c == 'e';
}

bool go(vector<int>& dot, string& s, int i) {
    if (i == s.size()) {
        return true;
    }

    if (i + 2 <= s.size() and isC(s[i]) and isV(s[i + 1]) and go(dot, s, i + 2)) {
        dot.push_back(i + 2);
        return true;
    }
    if (i + 3 <= s.size() and isC(s[i]) and isV(s[i + 1]) and isC(s[i + 2]) and go(dot, s, i + 3)) {
        dot.push_back(i + 3);
        return true;
    }

    return false;
}

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dot;
    go(dot, s, 0);
    reverse(dot.begin(), dot.end());

    for (int i = 0, j = 0; i < n; ++i) {
        if (j < dot.size() and dot[j] == i) {
            cout << ".";
            ++j;
        }
        cout << s[i];
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