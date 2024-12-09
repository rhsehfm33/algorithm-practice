#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (char si : s) {
        ++m[si];
    }
    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](auto& l, auto& r) {
        return l.second < r.second;
    });
    for (auto& si : s) {
        if (si == v.front().first) {
            si = v.back().first;
            break;
        }
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}