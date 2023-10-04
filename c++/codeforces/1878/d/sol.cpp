#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> l(k), r(k);
    for (int i = 0; i < k; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> r[i];
    }

    vector<int> i2si(n + 2);
    for (int i = 0; i < k; ++i) {
        for (int li = l[i], ri = r[i]; li <= ri; ++li, --ri) {
            i2si[li] = ri;
            i2si[ri] = li;
        }
    }

    vector<int> ps(n + 2);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        ps[min(x, i2si[x])] += 1;
        ps[max(x, i2si[x]) + 1] -= 1;
    }

    for (int i = 1, cur = 0; i <= n; ++i) {
        cur += ps[i];
        if (cur % 2 == 0) {
            cout << s[i - 1];
        }
        else {
            cout << s[i2si[i] - 1];
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