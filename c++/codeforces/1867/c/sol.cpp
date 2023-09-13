#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int mn = s.back() + 1;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
        if (s[i] > i) {
            mn = i;
            break;
        }
    }

    while (true) {
        cout << mn << '\n';
        cin >> mn;
        if (mn == -1) {
            cout.flush();
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}