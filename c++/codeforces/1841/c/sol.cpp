#include <bits/stdc++.h>

using namespace std;

int getSum(string& s) {
    int result = 0;
    for (int i = s.size() - 1, mx = -1; i >= 0; --i) {
        mx = max(mx, s[i] - 'A');
        if (s[i] - 'A' < mx) {
            result -= pow(10, s[i] - 'A');
        }
        else {
            result += pow(10, s[i] - 'A');
        }
    }

    return result;
}

void solve(int _ti) {
    string s;
    cin >> s;
    vector<bool> up(128), down(128);

    int ans = getSum(s);
    for (int i = 0; i < s.size(); ++i) {
        if (up[s[i]]) {
            continue;
        }
        up[s[i]] = true;
        
        char org = s[i];
        for (char ch = org + 1; ch <= 'E'; ++ch) {
            s[i] = ch;
            ans = max(ans, getSum(s));
        }
        s[i] = org;
    }

    for (int i = s.size() - 1; i >= 0; --i) {
        if (down[s[i]]) {
            continue;
        }
        down[s[i]] = true;
        
        char org = s[i];
        for (char ch = org - 1; ch >= 'A'; --ch) {
            s[i] = ch;
            ans = max(ans, getSum(s));
        }
        s[i] = org;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}