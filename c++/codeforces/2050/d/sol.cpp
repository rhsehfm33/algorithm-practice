#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    string s;
    cin >> s;

    vector<char> v;
    for (int i = 0, vi = 0; i < s.size(); ++i) {
        while (v.size() < 9 and vi < s.size()) {
            v.push_back(s[vi++]);
        }

        int mxi = 0;
        for (int j = 1; j < v.size(); ++j) {
            if (v[j] - j > v[mxi] - mxi) {
                mxi = j;
            }
        }
        s[i] = v[mxi] - mxi;
        v.erase(v.begin() + mxi);
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