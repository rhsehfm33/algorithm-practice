#include <bits/stdc++.h>

using namespace std;

int _ti;

int getMin(vector<int> s, int ti) {
    s[ti] = s[ti] * 10 + s[ti + 1];
    s.erase(s.begin() + ti + 1);
    int result = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (result <= 1 or s[i] <= 1) {
            result *= s[i];
        } else {
            result += s[i];
        }
    }
    return result;
}

void solve() {
    int n, ans = 1e9;
    cin >> n;
    vector<int> s(n);
    for (auto& si : s) {
        char ch;
        cin >> ch;
        si = ch - '0';
    }

    for (int i = 0; i + 1 < s.size(); ++i) {
        ans = min(ans, getMin(s, i));
    }
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