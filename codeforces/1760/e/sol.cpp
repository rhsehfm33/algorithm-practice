#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> c0(n + 2), c1(n + 2);
    for (int i = 1; i <= n; ++i) {
        c0[i] = !a[i] + c0[i - 1];
        c1[i] = a[i] + c1[i - 1];
    }

    ll base = 0, mxChange = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            base += c0[n] - c0[i];
            mxChange = max(mxChange, (ll)c1[i - 1] - (c0[n] - c0[i]));
        }
        else {
            mxChange = max(mxChange, (ll)(c0[n] - c0[i]) - c1[i - 1]);
        }
    }

    cout << base + mxChange << '\n';
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