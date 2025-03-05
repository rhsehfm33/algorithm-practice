#include <bits/stdc++.h>

using namespace std;

int _ti;

void check_min(vector<int>& a, int ai, int sum, int& mn, int& l, int& r) {
    for (int i = ai + 1; i < a.size(); ++i) {
        if (a[i] > a[ai]) {
            ++sum;
        } else if (a[i] < a[ai]) {
            --sum;
        }
        if (sum < mn) {
            mn = sum;
            l = ai + 1;
            r = i + 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int sum = 0;
    for (int r = 1; r < n; ++r) {
        for (int l = 0; l < r; ++l) {
            sum += a[r] < a[l];
        }
    }

    int mn = sum, l = 1, r = 1;
    for (int i = 0; i < n; ++i) {
        check_min(a, i, sum, mn, l, r);
    }
    cout << l << ' ' << r << '\n';
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