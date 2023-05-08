#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int ans = 0;
    for (char ch : s) {
        ans += (ch - '0');
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}