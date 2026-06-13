#include <bits/stdc++.h>
using namespace std;

int _ti;

void go(string& s, int n, int& k, string& ans) {
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            continue;
        }
        stack<int> l, r;
        while (i < n) {
            if (s[i] == '(') {
                l.push(i);
            } else {
                r.push(i);
            }
            if (l.size() <= r.size()) {
                break;
            }
            ++i;
        }
        if (l.size() > r.size()) {
            while (k and r.size()) {
                ans[r.top()] = '1';
                r.pop();
                --k;
            }
        } else {
            while (k and l.size()) {
                ans[l.top()] = '1';
                l.pop();
                --k;
            }
        }
    }
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string ans(n, '0');
    go(s, n, k, ans);
    cout << ans << '\n';
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