#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    int mex = 0;
    vector<int> mnc(n + 5), mxc(n + 5);
    for (int i = 0; ; ++i) {
        if (i >= n or a[i] > mex) {
            mnc[mex] = 0;
            mxc[mex] = (n - i) + (i - mex);
            break;
        }
        if (a[i] == mex) {
            ++mex;
        }
        ++mnc[a[i]];
        if (!i or a[i] > a[i - 1]) {
            mxc[a[i]] = n - i + (i - a[i]);
        }
    }

    vector<int> ps(n + 5);
    for (int i = 0; i <= n; ++i) {
        if (mnc[i] or i == mex) {
            ++ps[mnc[i]];
            --ps[mxc[i] + 1];
        }
    }

    for (int i = 0, sum = 0; i <= n; ++i) {
        sum += ps[i];
        cout << sum << ' ';
    }
    cout << '\n';
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