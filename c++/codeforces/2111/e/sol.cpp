#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string s;
    int n, q;
    cin >> n >> q >> s;
    set<int> sa[3][3];
    for (int i = 0; i < q; ++i) {
        char c1, c2;
        cin >> c1 >> c2;
        sa[c1 - 'a'][c2 - 'a'].insert(i);
    }

    for (char& si : s) {
        if (si == 'b') {
            if (sa[1][0].size()) {
                sa[1][0].erase(sa[1][0].begin());
                si = 'a';
            } else if (sa[1][2].size() and sa[2][0].size()
            and *sa[1][2].begin() < *sa[2][0].rbegin()) {
                sa[2][0].erase(sa[2][0].lower_bound(*sa[1][2].begin()));
                sa[1][2].erase(sa[1][2].begin());
                si = 'a';
            }
        } else if (si == 'c') {
            if (sa[2][0].size()) {
                sa[2][0].erase(sa[2][0].begin());
                si = 'a';
            } else if (sa[2][1].size()) {
                if (sa[1][0].size() and *sa[2][1].begin() < *sa[1][0].rbegin()) {
                    sa[1][0].erase(sa[1][0].lower_bound(*sa[2][1].begin()));
                    sa[2][1].erase(sa[2][1].begin());
                    si = 'a';
                } else {
                    sa[2][1].erase(sa[2][1].begin());
                    si = 'b';
                }
            }
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