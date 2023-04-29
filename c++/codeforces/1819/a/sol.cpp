#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    multiset<int> ms;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ms.insert(ai);
    }

    int mex = 0;
    for (int num = 0; num <= n; ++num) {
        if (ms.count(num) == 0) {
            mex = num;
            break;
        }
    }

    if (mex == n) {
        cout << "No\n";
        return;
    }

    int l = n + 1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mex + 1) {
            l = min(l, i);
            r = max(r, i);
        }
    }

    if (r == -1) {
        cout << "Yes\n";
        return;
    }

    for (int i = l; i <= r; ++i) {
        ms.erase(ms.find(a[i]));
    }

    for (int i = 0; i < mex; ++i) {
        if (ms.count(i) == 0) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}