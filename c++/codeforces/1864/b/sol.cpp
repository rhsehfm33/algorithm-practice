#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2 == 0) {
        sort(s.begin(), s.end());
        cout << s;
        return;
    }

    string s1, s2;
    for (int i = 0; i < n; i += 2) {
        s1 += s[i];
        s2 += (i + 1 < n ? string(1, s[i + 1]) : "");
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i <= n / 2; ++i) {
        if (i < s1.size()) {
            cout << s1[i];
        }
        if (i < s2.size()) {
            cout << s2[i];
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}