#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0, cur = 1; i < s.size(); ++i) {
        int target = s[i] == '0' ? 10 : s[i] - '0';
        ans += abs(target - cur) + 1;
        cur = target;
    }
    cout << ans << '\n';
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