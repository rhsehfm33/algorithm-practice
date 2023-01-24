#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    string s;
    cin >> n >> s;
    set<string> strs;
    for (int i = 0; i < (int)s.size() - 2; ++i) {
        string cur_str = s.substr(i, 2);
        string next_str = s.substr(i + 1, 2);
        if (strs.count(next_str)) {
            cout << "YES\n";
            return;
        }
        strs.insert(cur_str);
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