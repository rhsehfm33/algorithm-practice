#include <bits/stdc++.h>

using namespace std;

int go(vector<array<int, 2>>& lr, string& s, int i) {
    if (i == 0) {
        return 1e9;
    }
    if (lr[i][0] == 0 and lr[i][1] == 0) {
        return 0;
    }
    
    return min((s[i] != 'L') + go(lr, s, lr[i][0]), (s[i] != 'R') + go(lr, s, lr[i][1]));
}

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<array<int, 2>> lr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> lr[i][0] >> lr[i][1];
    }
    cout << go(lr, s, 1) << '\n';
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