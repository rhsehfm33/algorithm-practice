#include <bits/stdc++.h>
using namespace std;

int _ti;
vector<int> p;

void preset() {
    vector<bool> e(6e6, true);
    for (int i = 2; p.size() < 4e5; ++i) {
        if (!e[i]) {
            continue;
        }
        p.push_back(i);
        for (int j = i + i; j < 6e6; j += i) {
            e[j] = false;
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
    sort(a.begin(), a.end());

    int l = 0, h = n - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        long long c = 0;
        for (int i = 0; i + m < n; ++i) {
            if (a[i + m] >= p[i]) {
                c += abs(p[i] - a[i + m]);
            } else {
                c -= abs(p[i] - a[i + m]);
            }
        }
        if (c >= 0) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << h + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}