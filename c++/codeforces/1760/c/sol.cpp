#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> s(n);
    int mxi1 = -1, mxi2 = -1;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (mxi1 == -1 or s[mxi1] < s[i]) {
            mxi2 = mxi1;
            mxi1 = i;
        }
        else if (mxi2 == -1 or s[mxi2] < s[i]) {
            mxi2 = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != mxi1) {
            cout << s[i] - s[mxi1] << ' ';
        }
        else {
            cout << s[i] - s[mxi2] << ' ';
        }
    }
    cout << '\n';
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